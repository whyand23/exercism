#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H

typedef struct transcription {
    char *dna; 
    char *rna;
    struct transcription *next;
} data_t;
char *to_rna(const char *dna);
data_t *init(void);
char *iterator(const char *dna);
char *finder(data_t *anything, const char *foo);
void free_map(data_t *something);

#endif
