#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int temp = 0;
    int length = scores_len;
    for(int i = 0; i < length; i++) {
        if(temp < scores[i]) {
            temp = scores[i];
        }
    }
    return temp;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    int temp = 0;
    int length = scores_len;
    int32_t array[length];
    memcpy(array, scores, sizeof(array));
    
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if(array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    int foo = length < 3 ? length : 3;
    int result[foo];
    for(int i = 0; i < foo; i++) {
        result[i] = array[i];
        output[i] = array[i];
    }
    return sizeof(result) / sizeof(result[0]);
}