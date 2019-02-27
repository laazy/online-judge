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
}
