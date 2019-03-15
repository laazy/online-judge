#include "unordered.h"
#include "../util.h"
#include "../main.h"

#define null 0

void test_find_couple(){
    vector<vector<int>> nums1 {{1,  1}, 
                           {2,  1},{1,  3},
                       {1,  2},{1,  1},{3,  3}};
    Couple couple = Couple();
    cout << couple.find_couple(nums1) << endl;
}


int func(){
    test_find_couple();
    return 0;
}
