#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);
unsigned int *multiples(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit, size_t *out_len);
unsigned int remove_dupe(unsigned int *array, size_t array_size);
int comparator(const void *a, const void *b);
#endif
