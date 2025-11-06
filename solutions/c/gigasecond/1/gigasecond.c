#include "gigasecond.h"
#include <string.h>

void gigasecond(time_t input, char *output, size_t size) {
    time_t foo = input + 1000000000; //one billion or 10 to the power of 9
    struct tm utc = *gmtime(&foo);
    char buffer[size];
    strftime(buffer, sizeof buffer, "%Y-%m-%d %H:%M:%S", &utc);
    memcpy(output, buffer, size);
}