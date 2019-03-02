#include "other_question.h"

int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = n * 0x01010101;
    return n >> 24;
}

int hammingWeight2(uint32_t n) {
    int ans = 0;
    for(; n != 0; n = n & (n - 1)){
        ans++;
    }
    return ans;
}