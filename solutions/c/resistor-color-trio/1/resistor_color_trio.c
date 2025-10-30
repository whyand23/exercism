#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *array) {
    resistor_value_t new = {0}; // initialize all members to 0
    unsigned long main_val = 0;
    for(int i = 0; i < 2; i++) {
        main_val = main_val * 10 + array[i];
    }
  
    int exponent = array[2];
    for(; exponent > 0; exponent--){
        main_val = main_val * 10;
    }

    unsigned long temp = main_val;
    while(temp >= 1000){
        temp /= 1000;
    }
    new.value = temp; 
    
    if(main_val >= 1000000000) {
        new.unit = GIGAOHMS;
    } else if(main_val >= 1000000) {
        new.unit = MEGAOHMS;
    } else if(main_val >= 1000) {
        new.unit = KILOOHMS;
    } else {
        new.unit = OHMS;
    }

    return new;
}