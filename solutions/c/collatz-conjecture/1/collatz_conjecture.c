#include "collatz_conjecture.h"

int steps(int start) {
    int step_counter = 0;
    
    // edge case
    if (start < 1) {
        return ERROR_VALUE;
    }

    if (start == 1) {
        return step_counter;
    } else if (start % 2 == 0) {
        return step_counter = 1 + steps(start / 2);
    } else if (start % 2 != 0) {
        step_counter++;
        return step_counter = 1 + steps(start * 3 + 1);
    }
    
    
    return step_counter;
    
}
