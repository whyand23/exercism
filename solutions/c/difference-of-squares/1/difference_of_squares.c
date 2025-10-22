#include "difference_of_squares.h"
#include <stdio.h>

// square function
unsigned int square(unsigned int a);

unsigned int square(unsigned int a) {
    return a * a;
}

unsigned int sum_of_squares(unsigned int number) {
    unsigned int i = 0;
    int numbers[number];
    int sum = 0;

    for(i = 0; i < number; i++) {
        numbers[i] = i + 1;
        numbers[i] = square(numbers[i]);
        sum += numbers[i];
    }
    
    return sum;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int i = 0;
    int numbers[number];
    int sum = 0;

    // make input number into array
    for (i = 0; i < number; i++){
        numbers[i] = i + 1; // +1 because i start from zero
        sum += numbers[i];
    }

    return square(sum);
}

unsigned int difference_of_squares(unsigned int number) {
    int sumOfSquares = sum_of_squares(number);
    int squareOfSum = square_of_sum(number);
    return squareOfSum - sumOfSquares;
}