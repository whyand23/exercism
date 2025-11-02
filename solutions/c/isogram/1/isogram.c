#include "isogram.h"
#include <ctype.h>

bool is_isogram(const char phrase[]) {
    if(!phrase) return 0;
    for(int i = 0; phrase[i] != '\0'; i++) {
        if(isalpha(phrase[i])) {
            for(int j = 0; phrase[j] != '\0'; j++) {
                if(j == i) continue;
                if(tolower((int)phrase[i]) == tolower((int)phrase[j])) return 0;
            }
        }
    }
    return 1;
}