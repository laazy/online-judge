#include "sort_and_search.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, ptr = m + n - 1;
    while(i >= 0 && j >= 0){
        if (nums1[i] > nums2[j]){
            nums1[ptr] = nums1[i];
            i--;
        }else{
            nums1[ptr] = nums2[j];
            j--;
        }
        ptr--;
    }
    for(; j >= 0; j--){
        nums1[j] = nums2[j];
    }
}

bool isBadVersion(int version){
    return version >= 4;
}

int firstBadVersion(int n) {
    if (isBadVersion(1)){
        return 1;
    }
    int low = 1, high = n, cur;
    while ((high - low) > 1){
        cur = low / 2 + high / 2 + (low % 2 + high % 2) / 2 ;
        if (isBadVersion(cur)){
            high = cur;
        }else{
            low = cur;
        }
    }
    return high;
}