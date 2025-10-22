#include "rna_transcription.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



data_t *init(void) {
    data_t *head = (data_t *) malloc(sizeof(data_t));
    
    head->dna = "G";
    head->rna = "C";
    head->next = (data_t *) malloc(sizeof(data_t));
    head->next->dna = "C";
    head->next->rna = "G";
    head->next->next = (data_t *) malloc(sizeof(data_t));
    head->next->next->dna = "T";
    head->next->next->rna = "A";
    head->next->next->next = (data_t *) malloc(sizeof(data_t));
    head->next->next->next->dna = "A";
    head->next->next->next->rna = "U";
    head->next->next->next->next = NULL;
    
    return head;
}


// comparing to the data
char *finder(data_t *anything, const char *foo){
    data_t *current = anything;
    char *temp = NULL;

    while(current != NULL) {
        if(strcmp(current->dna, foo) == 0) 
            return temp = current->rna;
        current = current->next;
    }
    return temp;
}

// iterating and save the result to array
char *iterator(const char *dna){
    int length = strlen(dna);
    const char *input = dna;
    char *result = malloc(length + 1);
    data_t *map = init();
    char base[2];
    base[1] = '\0';
    
    for(int i = 0; i < length; i++){
        base[0] = input[i];
        result[i] = *finder(map, base);
    }
    result[length] = '\0';
    free_map(map);
    return result;
}

// freeing map
void free_map(data_t *something) {    
    while(something != NULL) {
        data_t *next = something->next;
        free(something);
        something = next;
    }
}

char *to_rna(const char *dna) {
    if(strlen(dna) == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    char *result = iterator(dna);
    return result;
}




