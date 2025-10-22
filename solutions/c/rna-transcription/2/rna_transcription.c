#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char foo[256] = {0};
void init(void) {
    foo['G'] = 'C';
    foo['C'] = 'G';
    foo['T'] = 'A';
    foo['A'] = 'U';
}

char *to_rna(const char *dna) {
    if(strlen(dna) == 0) {
        char *bar = malloc(1);
        bar[0] = '\0';
        return bar;
    }
    
    int length = strlen(dna);
    char *result = malloc(length + 1);
    init();
    for(int i = 0; i < length; i++) {
        result[i] = foo[(unsigned int)dna[i]];
    }
    // add terminator
    result[length] = '\0';
    return result;
}