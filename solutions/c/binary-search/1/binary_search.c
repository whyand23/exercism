#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {   
    if((length == 0) | !arr) return NULL;
    int low = 0;
    int high = length;
    int middle;
    while(low <= high) {
        middle = (low + high) / 2;
        if(arr[middle] == value) return &arr[middle];
        if(arr[middle] >= value) {
            high = middle - 1;
        }
        if(arr[middle] <= value) {
            low = middle + 1;
        }
    }
    return NULL;
}