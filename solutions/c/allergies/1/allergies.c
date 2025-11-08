#include "allergies.h"

allergen_list_t get_allergens(int input) {
    input &= 0xFF; // compares & to 255(0xFF)
    int info[ALLERGEN_COUNT] = {1, 2, 4, 8, 16, 32, 64, 128};
    int number = input;
    allergen_list_t new = {0}; // declared locally need to be init to 0 if not default will be garbo 
    for(int i = ALLERGEN_COUNT - 1; i >= 0; i--) {
        if(info[i] <= number) {
            new.count++;
            number -= info[i];
            new.allergens[i] = 1;
        }
    }
    return new;
}

bool is_allergic_to(allergen_t compare, int input) {
    allergen_list_t foo = get_allergens(input);
    return foo.allergens[compare];
}