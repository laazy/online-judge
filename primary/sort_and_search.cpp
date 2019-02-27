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

int firstBadVersion(int n) {

}