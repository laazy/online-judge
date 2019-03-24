#include "backtracking.h"

/**
 * 这道题同样可以用队列实现，相对用向量而言会节省一定的运行时空间
 * 事实上，每个向量在每次迭代时的空间大小也可以计算出来，所以可以预先开辟节省空间
 */ 
vector<string> letterCombinations(string digits){
    if (digits.empty()){
        return {};
    }
    vector<string> letter_array = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<int> input_digits;
    // convert input
    for (auto &i : digits){
        if (i >= '2' && i <= '9'){
            input_digits.push_back(i - '2');
        }
    }

    vector<string> last = {""}, cur;
    for (int i : input_digits){
        for (const auto &j : last){
            for (const auto &k : letter_array[i]){
                cur.push_back(j+k);
            }
        }
        last.swap(cur);
        cur.clear();
    }
    return last;
}

void gp_helper(string &s, int n, int left, int right, vector<string> ans){
    if (left > n){
        ans.push_back(s);
    }
    string tmp = s + '(';
    gp_helper(tmp, n, left + 1, right, ans);
    if (left == right){
        return;
    }
    string tmp1 = s + ')';
    gp_helper(tmp1, n, left, right + 1, ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string initial = "";
    gp_helper(initial, n, 0, 0, ans);
    return ans;
}