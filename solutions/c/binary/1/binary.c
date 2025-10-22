#include "binary.h"
#include <string.h>
#include <math.h>

int convert(const char *input) {
    int length = strlen(input);
    int result = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] - '0' > 1) return INVALID; // '0' is ascii 48
        result += (input[i] - '0') * pow(2, (length - 1) - i);
    }
    
    return result;
}