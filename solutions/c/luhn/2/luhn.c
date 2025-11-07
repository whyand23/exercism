#include "luhn.h"

bool luhn(const char *num) {
    size_t len = strlen(num);
    int run = 0;
    int result = 0;
    int temp = 0;
    int number;

    if(len < 2) return 0;
    for(int i = len - 1; i >= 0; i--) {
        if(num[i] == ' ') {
            continue;
        } else if(num[i] >= '0' && num[i] <= '9') {
            run++;
            number = num[i] - '0';
            temp = run % 2 == 0 ? number * 2 : number;
            result += temp > 9 ? temp - 9 : temp;
        } else return 0;
    }

    if(result == 0 && run < 2) {
        return 0;
    } else if(result % 10 == 0) {
        return 1;
    } else return 0;
}