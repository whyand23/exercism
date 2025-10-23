#include "perfect_numbers.h"

int aliquot(int input) {
    int sum = 0;
    for(int i = 1; i < input; i++){
        if(input % i == 0) sum += i;
    }
    return sum;
}

int classify_number(int input){
    if(input < 1) return ERROR;
    if(aliquot(input) == input) return PERFECT_NUMBER;
    if(aliquot(input) > input) return ABUNDANT_NUMBER;
    if(aliquot(input) < input) return DEFICIENT_NUMBER;
    return ERROR;
}
