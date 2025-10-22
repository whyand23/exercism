#include "darts.h"

const int radii[3] = {1, 5, 10};
const int scores[3] = {10, 5, 1};

uint8_t score(coordinate_t something) {
    
    float px = something.x;
    float py = something.y;

    // The distance formula between two points on Concentric Circles
    float distance_squared = (px - 0)*(px - 0) + (py - 0)*(py - 0); 

    for (size_t i = 0; i <= (sizeof(radii) / sizeof(radii[0])); i++) {
        if (distance_squared <= radii[i] * radii[i]) {
            return scores[i]; // ik this is garbage
        }
    }
    return 0;


}

