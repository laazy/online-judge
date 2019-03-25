#include "sort_search.h"
#include "../util.h"
#include "../main.h"

#define null 0

void test_sortColors(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    print_vec(nums);
}

int func(){
    test_sortColors();
    return 0;
}
