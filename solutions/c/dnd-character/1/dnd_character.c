#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>	

int ability(void) {
    int max_num = 6;
    int min_num = 1;
    int throw = 0;
    int result[4] = {0};
    int temp = 0;

    for(int i = 0; i < 4; i++){
        throw = rand() % (max_num + 1 - min_num) + min_num;
        result[i] = throw;
    }

    for(int i = 0; i < 4;i++){
        for(int j = i + 1; j < 4;j++){
            if(result[i] > result[j]){
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return result[1] + result[2] + result[3];
}

int modifier(int score) {
    return (int)floor((score - 10.0) / 2.0); 
}

// assign it to the struct
dnd_character_t make_dnd_character(void) {
    const int bar = ability();
    dnd_character_t foo = {
    .strength = ability(),
    .dexterity = ability(),
    .constitution = bar,
    .intelligence = ability(),
    .wisdom = ability(),
    .charisma = ability(),
    .hitpoints = 10.0 + modifier(bar)
    };
    return foo;
}