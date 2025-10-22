#include "eliuds_eggs.h"

unsigned int egg_count(int args){
    int input = args;
    //int binary = 0;
    int remainder = 0;
    int count = 0;
    while(input > 0) {
        remainder = input % 2;
        if(remainder == 1) count += 1;
        input = input / 2;
        //binary = binary * 10 + remainder;
    }
    
    return count;
}