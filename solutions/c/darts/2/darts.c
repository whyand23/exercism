#include "darts.h"

//const int radii[3] = {1, 5, 10};
//const int scores[3] = {10, 5, 1};

const float INNER_RING = 1.0f;
const float MIDDLE_RING = 5.0f;
const float OUTER_RING = 10.0f;

static float radius(coordinate_t something){
    float px = something.x;
    float py = something.y;

    // The distance formula between two points on Concentric Circles
    // float distance_squared = (px - 0)*(px - 0) + (py - 0)*(py - 0);
    return hypot(px, py);
}

static bool scoring(float radius, float ring) {
    return radius <= ring;
}

uint8_t score(coordinate_t something) {

    /* for (size_t i = 0; i <= (sizeof(radii) / sizeof(radii[0])); i++) {
        if (distance_squared <= radii[i] * radii[i]) {
            return scores[i]; // ik this is garbage
        }
    */
    
    float distance = radius(something);
    
    // result 
    if (scoring(distance, INNER_RING)) {
        return 10;
    } else if (scoring(distance, MIDDLE_RING)) {
        return 5;
    } else if (scoring(distance, OUTER_RING)) {
        return 1;
    } 
    
    return 0;
    }

    
