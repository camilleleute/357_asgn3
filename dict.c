/* Defines functions for implmenting a dictionary.
 * CSC 357, Assignment 3
 * Given code, Winter '24 */

#include <stdlib.h>
#include "dict.h"
#define INIT_CAP 30

/* dcthash: Hashes a string key.
 * NOTE: This is certainly not the best known string hashing function, but it
 *       is reasonably performant and easy to predict when testing. */
static unsigned long int dcthash(char *key) {
    unsigned long int code = 0, i;

    for (i = 0; i < 8 && key[i] != '\0'; i++) {
        code = key[i] + 31 * code;
    }

    return code;
}

/* dctcreate: Creates a new empty dictionary.
 * TODO: Implement this function. It should return a pointer to a newly
 *       dynamically allocated dictionary with an empty backing array. */
Dict *dctcreate() {
	
	Dict *dict; 
	dict = (Dict *)malloc(sizeof(Dict));
	if (dict == NULL) {
		free(dict);
		return NULL;
	} else {
		dict -> arr = (Node**)calloc(INIT_CAP, sizeof(Node**));
		if (dict->arr == NULL) {
			free(dict);
			return NULL;
		}	
	}
	dict->cap = INIT_CAP;
	dict->size = 0;
	return dict;
}


/* dctdestroy: Destroys an existing dictionary.
 * TODO: Implement this function. It should deallocate a dictionary, its
 *       backing array, and all of its nodes. */
void dctdestroy(Dict *dct) {
	if (dct == NULL){
		return;
	} else {
		int i = 0;
		for (i = 0; i < dct->size; i++) {
			Node *curr;
			*curr = dct->arr[i].next;
		}	
	}
	
    return;
}

/* dctget: Gets the value to which a key is mapped.
 * TODO: Implement this function. It should return the value to which "key" is
 *       mapped, or NULL if it does not exist. */
void *dctget(Dict *dct, char *key) {
    return NULL;
}

/* dctinsert: Inserts a key, overwriting any existing value.
 * TODO: Implement this function. It should insert "key" mapped to "val".
 * NOTE: Depending on how you use this dictionary, it may be useful to insert a
 *       dynamically allocated copy of "key", rather than "key" itself. Either
 *       implementation is acceptable, as long as there are no memory leaks. */
void dctinsert(Dict *dct, char *key, void *val) {
	int idx = 0;
	idx = (dcthash(key))%INIT_CAP;
	
	Node curr*;
	curr = dct->arr[idx];
	
	while (curr != NULL) {
		if (strcmp(curr->key, key) == 0) {
		curr->val = val;
		return;
		}
	curr = curr->next;	
	}
		
	Node *node = (Node *)malloc(sizeof(Node));
	
	if (node == NULL){
		free(node);
		return;
	} else {

				
	}
	
	
return;
}

void collision(){
}

/* dctremove: Removes a key and the value to which it is mapped.
 * TODO: Implement this function. It should remove "key" and return the value
 *       to which it was mapped, or NULL if it did not exist. */
void *dctremove(Dict *dct, char *key) {
    return NULL;
}

/* dctkeys: Enumerates all of the keys in a dictionary.
 * TODO: Implement this function. It should return a dynamically allocated array
 *       of pointers to the keys, in no particular order, or NULL if empty. */
char **dctkeys(Dict *dct) {
    return NULL;
}
