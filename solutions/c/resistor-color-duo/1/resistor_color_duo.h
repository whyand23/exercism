#include <stdint.h>
#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

#define COLORS \
BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum {
    COLORS
} resistor_band_t;

uint16_t color_code(resistor_band_t array[]);
#endif
