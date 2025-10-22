#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int foo = 0;
    int lenght = strlen(lhs); // bcs running strlen straight on loop is un efficient

    if(strlen(lhs) != strlen(rhs)) {
        return -1; 
    }

    for(int i = 0; i < lenght; i++) {
        if(lhs[i] != rhs[i]){
            foo += 1;
        }
    } 
    
    // edge case catcher too as default is 0
    return foo; 
}