#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>
#include <stdio.h>

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
    PLANET_COUNT,
} planet_t;

float age(planet_t planet, int64_t seconds);
float get_orbital(planet_t planet);

#endif
