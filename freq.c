#include <stdio.h>
#include "dict.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char* key;
	int num;
} Pair;

int main(int argc, char* argv[]) {
	unsigned int num = 5;
	char *line = NULL;
	char ** keys = NULL;
	int j = 0;
        int val;
        Pair** pair;
	FILE *file;
	Dict *dct = dctcreate();
	if (argc > 2) {
		printf("./freq: Too many arguments\n");
        	exit(1);
    	}
	if (argc < 2) {
		printf("./freq: Too few arguments\n");
		exit(1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("./freq: No such file or directory\n");
		exit(1);
	}
	line = (char *)malloc(sizeof(char) * (num + 1));
	while (fgets(line, num, file) != NULL) {
                while (line[strlen(line)-1] != '\n'){
                                num = num*2;
                                line = (char *)realloc(line, sizeof(char) * (num + 1));
                                fseek(file, -strlen(line), SEEK_CUR);
                                fgets(line, num, file);
                        }
		parse(line, dct);	
	}
	pair = malloc(dct->size * sizeof(Pair*));
	for (j = 0; j < dct->size; j++){
		pair[j] = malloc(sizeof(Pair));
	}
	
	keys = dctkeys(dct);
	
	for (j = 0; j < dct->size; j++) {
		val = (long)dctget(dct, keys[j]);
		pair[j]->key = (char *)keys[j];
		pair[j] -> num = val;
	}
	
	qsort(pair, dct->size, sizeof(char *), comparePair);
	
	for (j = 0; j < dct->size && j<10; j++){
		num = pair[j]->num;
		printf("%s (%d)\n", pair[j]->key, num);
	} 
	
	for (j = 0; j<dct->size; j++) {
		free(pair[j]);
	}
	free(pair);
	free(line);
	free(keys);
	dctdestroy(dct);	
	fclose(file);
	return 0;
}


int comparePair(const void* a, const void* b) {
	const Pair *pair1 = *(const Pair **) a;
	const Pair *pair2 = *(const Pair **) b;
	if ((pair1->num) != (pair2->num)){
		return (pair2->num) - (pair1->num);
	}
	return strcmp(pair1->key, pair2->key);
}

void parse(char *line, Dict* dct) {
	void* val;
	char *delimiters = " \t\n\f\v\r";	
	char *word;
	word = strtok(line , delimiters);
	while (word != NULL) {
			word = makeWord(word);			
			val = dctget(dct, word);		
			if (val != NULL){
				dctinsert(dct, word, (void*)((long)val + 1)); 
			} else {
				dctinsert(dct, word, (void*)(long)1);
			}	
		}	
		word = strtok(NULL, delimiters);		
	}


int checkWord(char *word) {
	int length = strlen(word);
	int i = 0;
	for (i = 0; i < length; i++) {
		if ((isalpha(word[i])==0) && word[i] != '\'' && word[i] != ','&& word[i] !='.'){ 		
			return 1;
		}
	}
	return 0;
		
}

char* makeWord(char* word) {
	int i, j = 0;
	for (i = 0; word[i] != '\0'; i++) {
		if (isalpha(word[i])!=0){
			word[j++] = tolower(word[i]);
		}
	}
	word[j] = '\0';
	return word;
}










