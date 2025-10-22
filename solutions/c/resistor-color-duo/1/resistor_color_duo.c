#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *colors) {
    int bar[2] = {colors[0], colors[1]};
    int foo = 0;
    for(int i = 0; i < 2; i++) {
        foo = foo * 10 + bar[i]; 
    }
    
    return foo;
}

