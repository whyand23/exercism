#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    /*int foo = 0;*/
    /*int lenght = strlen(lhs);*/

    // edge case if they are empty
    if(!lhs || !rhs) {
        return 0; 
    }

    int bar = 0;
    for(; *lhs && rhs; lhs++, rhs++) {
        if(*lhs != *rhs) {
            bar++;
        }
    }
    
    /* 
    for(int i = 0; i < lenght; i++) {
        if(lhs[i] != rhs[i]){
            foo += 1;
        }
    }
    */
    
    return (*lhs || *rhs) ? -1 : bar; 
}