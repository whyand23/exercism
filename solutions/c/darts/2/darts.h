#ifndef DARTS_H
#define DARTS_H
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t something);


#endif
