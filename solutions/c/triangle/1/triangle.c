#include "triangle.h"

bool is_degen(triangle_t sides) {
    if(sides.a + sides.b >= sides.c 
       && sides.b + sides.c >= sides.a 
       && sides.a + sides.c >= sides.b) {
        return 0;
       } else return 1;
}

bool is_equilateral(triangle_t sides) {
    if(is_degen(sides)) return 0;
    if(sides.a == sides.b && sides.c) {
        return 1;
    } else return 0;
}

bool is_isosceles(triangle_t sides) {
    if(is_degen(sides)) return 0;
    if(sides.a == sides.b || sides.a == sides.c || sides.b == sides.c) {
        return 1;
    } else return 0;
}

bool is_scalene(triangle_t sides) {
    if(is_degen(sides)) return 0;
    if(sides.a != sides.b && sides.a != sides.c && sides.b != sides.c) {
        return 1;
    } else return 0;
}
