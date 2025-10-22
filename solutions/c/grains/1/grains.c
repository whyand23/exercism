#include "grains.h"

uint64_t square(uint8_t index){
    uint64_t value[64];
    uint64_t container = 1;
    int i = 1;

    // edge case
    if (index > 64) {
        return 0;
    }
    
    value[0] = 0;
    for (i = 1; i <= 64; i++) {
        value[i] = container;
        container *= 2;
        
    }
    
    return value[index];  
}

uint64_t total(void) {
    int sum = 0;
    int i = 0;
    
    for (i = 0; i < 64; i++) {
        sum += square(i);
    }
    return sum;
}