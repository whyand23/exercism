#include "armstrong_numbers.h"

int power(int base, int exponent) {
    int foo = 1;
    for(int i = 0; i < exponent; i++) {
        foo *= base;
    }
    return foo;
}

int find_digits(int candidate) {
    int input = candidate;
    int count = 1;
    for(int i = 0; input > 9; i++) {
        input = input / 10;
        count++;
    }
    return count;
}

bool is_armstrong_number(int candidate) {
    if(candidate < 0) return 0;
    int digits = find_digits(candidate);
    int input = candidate;

    // write input to array
    int foo[digits];
    for(int i = 0; i < digits; i++) {
        foo[i] = input % 10;
        input = input / 10;
    }

    // sum of input own digits each raised to the power of digits.
    int sum = 0;
    for(int i = 0; i < digits; i++) {
        sum += power(foo[i], digits);
    }

    return candidate == sum;
}