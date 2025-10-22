#include "resistor_color.h"

// just calling enum on arg
uint16_t color_code(resistor_band_t color){
    resistor_band_t foo = color;
    return foo;
}

// colors function the test asked
const resistor_band_t *colors(void) {
    // static means this array stays in memory after the function ends
    static const resistor_band_t all_colors[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
    };

    return all_colors;
}
