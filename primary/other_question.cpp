#include "other_question.h"

int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = n * 0x01010101;
    return n >> 24;
}

int hammingWeight2(uint32_t n) {
    int ans = 0;
    for(; n != 0; n = n & (n - 1)){
        ans++;
    }
    return ans;
}

// 此处大概思想仍为计算异或结果的汉明重量
int hammingDistance(int x, int y) {
    uint32_t i = x ^ y;
    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
    i = i * 0x01010101;
    return i >> 24;
}

uint32_t reverseBits(uint32_t n){
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++){
        ans = ans << 1;
        ans = ans | ((n >> i) & 0x1);
    }
    return ans;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++){
        ans.push_back(vector<int>(i + 1));
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++){
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }  
    return ans;
}

bool isValid(string s){
    stack<char> symbol;
    while(!s.empty()){
        char temp = 0;
        switch (s.back())
        {
            case ')':case ']':case '}':
                symbol.push(s.back());
                break;
            case '(':
                temp = ')';
                break;
            case '[':
                temp = ']';
                break;
            case '{':
                temp = '}';
                break;
            default:
                return false;
        }
        if (temp != 0){
            if (!symbol.empty() && temp == symbol.top()){
                symbol.pop();
            }else{
                return false;
            }
        }
        s.pop_back();
    }
    return symbol.empty();
}

// 也可以用异或的方式
int missingNumber(vector<int> nums) {
    size_t size = nums.size();
    unsigned long total = (size * (size + 1)) / 2;
    for (int i : nums){
        total -= i;
    }
    return total;
}