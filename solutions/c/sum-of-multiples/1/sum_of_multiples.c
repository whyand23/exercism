#include "sum_of_multiples.h"
#include <stdlib.h>
#include <string.h>

unsigned int *multiples(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit, size_t *out_len) 
{
    unsigned int temp = 0;
    unsigned int *result = (unsigned int *)calloc(limit, sizeof(unsigned int));
    unsigned int foo = 0;
    
    for(unsigned int i = 0; i < number_of_factors; i++) {
        for(unsigned int j = 0; j < limit; j++) {
            temp = factors[i] * j;
            if(temp >= limit) break;
            if(temp < limit) {
                result[foo] = temp;
                foo++;
            }    
        }
    }
    *out_len = foo;
    return result;
}

// for qsort, because it not default for sorting int
int comparator(const void *a, const void *b) 
{
    const int x = *(const int*)a;
    const int y = *(const int *)b;
    return (x > y) - (x < y);
}

unsigned int remove_dupe(unsigned int *array, size_t array_size)
{
    qsort(array, array_size, sizeof(int), comparator);
    
    int j = 0;
    for(int i = 1; i < (int)array_size; i++) {
        if(array[i] != array[j]) {
            j++;
            array[j] = array[i];
        }
    }
    return j + 1;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) 
{
    // trying to get result of multiples as array, very messy i know
    // this will result in result array with bunch of zero at the end
    // result_len are saving real data length
    // clean arr just array without that zeroes
    size_t result_len = 0;
    unsigned int *result = multiples(factors, number_of_factors, limit, &result_len);
    unsigned int clean_arr[result_len];
    for(int i = 0; i < (int)result_len; i++) {
        clean_arr[i] = result[i];
    }

    // removing dupe, pushing dupe to the right
    // return proper array length with unique numbers that will be summed
    unsigned int working_len = remove_dupe(clean_arr, result_len);
    
    unsigned int sum = 0;
    for(unsigned int i = 0; i < working_len; i++) {
        sum += clean_arr[i];
    }
    return sum;
}
