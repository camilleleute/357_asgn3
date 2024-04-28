#include <stdio.h>
#include "dict.h"
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {
	unsigned int num = 5;
	char *line = NULL;
        FILE *file;
	if (argc != 2) {
        	return 1;
    	}
	file = fopen(argv[1], "r");
	if (file == NULL) {
		return 1;
	}
	line = (char *)malloc(sizeof(char) * (num + 1));
	while (fgets(line, num, file) != NULL) {
        	if (1+(unsigned int)strlen(line) == num) {
                	while (line[num - 1] != '\n' && (1+strlen(line) == num)){
                        	num = num*2;
                        	line = (char *)realloc(line, sizeof(char) * (num + 1));
                        	fseek(file, -strlen(line), SEEK_CUR);
				fgets(line, num, file);
                }
	}
		
	printf("%s",line);
	}
	free(line);	
	fclose(file);
	return 0;
}

