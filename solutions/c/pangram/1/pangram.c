#include "pangram.h"
#include <ctype.h>

bool is_pangram(const char *sentence) {
    if(!sentence) return 0;
    int pos;
    int bit = 0; // if not assigned to zero bitwise op will be based on memory val
    for(;*sentence != '\0'; sentence++) {
        if(isalpha(*sentence)) {
            pos = tolower((unsigned char)*sentence) - 'a';
            bit |= (1u << pos); // |= for bitwise is like +=
            if(bit == 0x3FFFFFF) return 1;
        }
    }
    return bit == 0x3FFFFFF; // its means 26 bit flipped into 1
}