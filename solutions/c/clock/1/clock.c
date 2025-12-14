#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void clamp(char *new, int h, int m) {
    if(h < 0) h = 0;
    if(h > 99) h = 99;
    if(m < 0) m = 0;
    if(m > 99) m = 99;

    new[0] = '0' + (h / 10);
    new[1] = '0' + (h % 10);
    new[2] = ':';
    new[3] = '0' + (m / 10);
    new[4] = '0' + (m % 10);
    new[5] = '\0';
}

clock_t clock_create(int hour, int minute) 
{
    clock_t new = {0};
    
    int m = minute;
    int h = hour;

    // wrap 60 minutes to an hour
    while(m >= 60) {
        m -= 60;
        h++;
    }
    
    // wrap hour if it more than 24 
    // (so next day)
    h = h % 24;

    // wrap negative minutes to negative hour
    while(m < 0) {
        m += 60;
        h--;
    }

    // negative hour will wrap to yesterday hours
    while(h < 0) h += 24;

    clamp(new.text, h, m);
    
    return new;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    clock_t new = {0};
    char *endptr;
    char *str = clock.text;

    int m;

    // string to int the first two before ':'
    int h = strtol(str, &endptr, 10);

    if(*endptr == ':') {
        str = endptr;
        str++;
        // string to int the last two after ':'
        m = strtol(str, &endptr, 10);
    }

    m += minute_add;
    // wrap 60 minutes to hour
    while(m >= 60) {
        m -= 60;
        h++;
    }

    h = h % 24;

    clamp(new.text, h, m);

    return new;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    clock_t new = {0};

    char *endptr;
    char *str = clock.text;

    int m;

    int h = strtol(str, &endptr, 10);

    if(*endptr == ':') {
        str = endptr;
        str++;
        m = strtol(str, &endptr, 10);
    }

    m -= minute_subtract;

    // wrap negative minutes to negative hour
    while(m < 0) {
        m += 60;
        h--;
    }

    // negative hour will wrap to yesterday hours
    while(h < 0) h += 24;

    // wrap extra hours to the next day
    h = h % 24;

    clamp(new.text, h, m);

    return new;
}

bool clock_is_equal(clock_t a, clock_t b) 
{
    return strcmp(a.text, b.text) == 0;
}