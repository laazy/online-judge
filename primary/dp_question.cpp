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
 * 这道题很经典，核心思想是这样：
 * 构造一个函数 f(n)，为以第n个数为结尾的最大子序列和
 * 很容易可以发现， 当f(n-1)已知时，f(n) = max(f(n-1) + A[n], A[n])
 * 这样就可以在一次遍历中，找到最大的一个子序列
 * 
 * 这道题的状态可以是 以n为结尾的最大子序列
 * 所以状态转移方程就是上述公式
 * 边界值自然就是第一个数
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

/**
 * 
 * 考虑F(n)为偷窃到第n家，那么记录最后一次偷窃的为m
 *         / max(F(n-1), F(n-2) + A[n]), n == m   
 * F(n) = <
 *         \ F(n-1) + A[n], n != m 
 * 有一个细节，如果F(n-1) == F(n-2) + A[n]时， 应当选取前一个，因为这会给后续留下空间，减少第一步执行次数
 */ 
int rob(vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }
    int fn = 0, fn1 = 0, fn2 = 0; 
    size_t last = -2;
    for (size_t i = 0; i < nums.size(); i++){
        if (last != i - 1){
            fn = fn1 + nums[i];
            last = i;
        } else if (fn1 >= fn2 + nums[i]){
            fn = fn1;
        } else {
            fn = fn2 + nums[i];
            last = i;
        }
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}
