#include "dp_question.h"
#include "../main.h"
#include "../util.h"

void test_climbStairs(){
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(5) << endl;
}

void test_maxProfit(){
    vector<int> nums = {7,1,5,3,6,4};
    cout << maxProfit(nums) << endl;
    vector<int> nums1 = {7,6,4,3,1};
    cout << maxProfit(nums1) << endl;
    vector<int> nums2 = {2,4,1};
    cout << maxProfit(nums2) << endl;
}

void test_maxSubArray(){
    vector<int> n1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(n1) << endl;
}

void test_rob(){
    vector<int> n1 = {1,2,3,1};
    cout << rob(n1) << endl;
    vector<int> n2 = {2,7,9,3,1};
    cout << rob(n2) << endl;
}


int func(){
    test_rob();
    return 0;
}