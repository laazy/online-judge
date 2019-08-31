#include "sort_search.h"
#include "../util.h"
#include "../main.h"

#define null 0

void test_sortColors(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    print_vec(nums);
}

void test_topKFrequent(){
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> nums1 = {-1, -1};
    print_vec(topKFrequent(nums, 2));
    print_vec(topKFrequent(nums1, 1));
}

void test_findKthLargest(){
    vector<int> nums1 = {3,2,1,5,6,4};
    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    cout << "your answer: " << findKthLargest(nums1, 2) << " correct answer: " << 5 << endl;
    cout << "your answer: " << findKthLargest(nums2, 4) << " correct answer: " << 4 << endl;
}

int func(){
    test_findKthLargest();
    return 0;
}
