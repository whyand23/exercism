#include "resistor_color.h"

// just calling enum on arg
uint16_t color_code(resistor_band_t color){
    resistor_band_t foo = color;
    return foo;
}

static resistor_band_t all_colors[10] = {COLORS};

// colors function the test asked
const resistor_band_t *colors(void) {
    return all_colors;
}
