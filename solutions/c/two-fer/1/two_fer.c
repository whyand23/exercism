#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name) {
    if(name == NULL) {
        strcpy(buffer, "One for you, one for me.");
    } else if(strcmp(name, "Alice") == 0) {
        strcpy(buffer, "One for Alice, one for me.");
    } else if(strcmp(name, "Bob") == 0) {
        strcpy(buffer, "One for Bob, one for me.");
    } 
}