#include "sort_and_search.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = n, j = 0, size = nums1.size(), ptr = 0;
    for (int i = size - 1; i >= n; i--){
        nums1[i] = nums1[i - n];
    }
    while(i < size && j < n){
        if (nums1[i] < nums2[j]){
            nums1[ptr] = nums1[i];
            i++;
        }else{
            nums1[ptr] = nums2[j];
            j++;
        }
        ptr++;
    }
    if (j != n){
        for(; j < n; j++){
            nums1[m + j] = nums2[j];
        }
    }
}