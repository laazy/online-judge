#include "dp_question.h"

int climbStairs(int n) {
    int n0 = 1, n1 = 1, n2 = 0;
    for (int i = 1; i < n; i++){
        n2 = n1;
        n1 = n0;
        n0 = n1 + n2;
    }
    return n0;
}

int maxProfit(vector<int>& prices) {
    int minprice = INT32_MAX ;
    int maxprofit = 0;
    for (size_t i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}

/**
 * 这道题难度很大，核心思想是这样：
 * 构造一个函数 f(n)，为以第n个数为结尾的最大子序列和
 * 很容易可以发现， 当f(n-1)已知时，f(n) = max(f(n-1) + A[n], A[n])
 * 这样就可以在一次遍历中，找到最大的一个子序列和
 */ 
int maxSubArray(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }
    int ans = INT32_MIN, fn = 0;
    for (size_t n = 0; n < nums.size(); n++){
        fn = max(fn + nums[n], nums[n]);
        if (fn > ans){
            ans = fn;
        }
    }
    return ans;
}

int rob(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }
    int total = nums[0];
    size_t last = 0;
    for (size_t i = 1; i < nums.size(); i++){
        if (last == i - 1){
            if (total < total - nums[last] + nums[i]){
                last = i;
                total += nums[i] - nums[last];
            }
        }else{
            total += nums[i];
            last = i;
        }
    }
    return total;
}
