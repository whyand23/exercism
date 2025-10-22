#include "raindrops.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    int factor;
    char *text;
} colors_t;

const colors_t SOUNDS[] = {
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"},
};

void convert(char result[], int drops) {

    /*
    if(drops % 3 == 0) strcat(result, "Pling");
    if(drops % 5 == 0) strcat(result, "Plang");
    if(drops % 7 == 0) strcat(result, "Plong");
    */

    /*
    sprintf(result, "%s%s%s", 
            drops % 3 == 0 ? "Pling" : "", 
            drops % 5 == 0 ? "Plang" : "", 
            drops % 7 == 0 ? "Plong" : "");
    */

    for(size_t i = 0; i < sizeof(SOUNDS) / sizeof(SOUNDS[0]); i++) {
        if(drops % SOUNDS[i].factor == 0) {
            strcat(result, SOUNDS[i].text);
        }
    }

    if(strlen(result) == 0) sprintf(result, "%d", drops);
}