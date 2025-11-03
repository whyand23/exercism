#include "isogram.h"
#include <stdint.h>

bool is_isogram(const char phrase[]) {
    if(!phrase) return 0;

    int32_t flag = 0;
    char foo = 'a';
    
    while(*phrase) {
        int letter = *phrase;
        if(letter >= 'a' && letter <= 'z') {
            foo = 'a';
        } else if(letter >= 'A' && letter <= 'Z') {
            foo = 'A';
        } else foo = 'X';

        if(foo != 'X') {
             if((flag & (1 << (letter - foo))) != 0) {
                 return 0;  
             } else {
            flag |= (1 << (letter - foo));
            } 
        } 
        phrase++;
    }
    return 1;
}