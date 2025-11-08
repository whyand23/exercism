#include "allergies.h"

allergen_list_t get_allergens(int input) {
    allergen_list_t new = {0}; // declared locally is needed to be init to 0 if not default will be garbo 
    for(int i = ALLERGEN_EGGS; i < ALLERGEN_COUNT; i++) {
        if(is_allergic_to((allergen_t)i, input)) {
            new.count++;
            new.allergens[i] = 1;
        }
    }
    return new;
}

bool is_allergic_to(allergen_t compare, int input) {
    return (input & 1 << compare) != 0;
}