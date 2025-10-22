#include "space_age.h"

const int earth_year = 31557600;

// assigning planet orbital values
float get_orbital(planet_t planet) {
   switch(planet) {
       case MERCURY: return 0.2408467f;
       case VENUS: return 0.61519726f;
       case EARTH: return 1.0f;
       case MARS: return 1.8808158f;
       case JUPITER: return 11.862615f;
       case SATURN: return 29.447498f;
       case URANUS: return 84.016846;
       case NEPTUNE: return 164.79132f;
       case PLANET_COUNT: return 0;
   }
    return 0
;
}

float age(planet_t planet, int64_t seconds) {
 
    // almost makes me crazy how unsigned enum works
    // edge case
    if(planet >= PLANET_COUNT || seconds < 0) {
       return -1.0f;
    } 
    
    float planet_year = earth_year * get_orbital(planet);
    float foo = seconds / planet_year;

    return foo;
}