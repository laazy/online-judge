#include "backtracking.h"
#include "../util.h"
#include "../main.h"

#define null 0

void print_string_matrix(vector<string> &strs){
    for (auto &i : strs){
        cout << i << " ";
    }
    cout << endl;
}

void test_letterCombinations(){
    auto ans = letterCombinations("23");
    print_string_matrix(ans);
}

void test_generateParenthesis(){
    auto ans = generateParenthesis(3);
    print_string_matrix(ans);
}

void test_permute(){
    vector<int> nums = {1,2,3};
    print_matrix(permute(nums));
}

void test_subsets(){
    vector<int> nums = {1,2,3};
    print_matrix(subsets(nums));
}

int func(){
    test_permute();
    return 0;
}
