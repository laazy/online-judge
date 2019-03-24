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

int func(){
    test_generateParenthesis();
    return 0;
}
