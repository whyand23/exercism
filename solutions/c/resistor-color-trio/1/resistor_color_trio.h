#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

typedef enum unit {
    OHMS,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS
}resistor_unit_t;

typedef struct foo {
    uint16_t value;
    resistor_unit_t unit;
}resistor_value_t;

typedef enum COLORS {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
}resistor_band_t;

resistor_value_t color_code(resistor_band_t *array);

#endif
