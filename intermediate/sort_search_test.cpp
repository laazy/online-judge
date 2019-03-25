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

int func(){
    test_topKFrequent();
    return 0;
}
