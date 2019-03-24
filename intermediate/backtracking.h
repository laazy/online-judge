#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits);

vector<string> generateParenthesis(int n);

vector<vector<int>> permute(vector<int>& nums);

vector<vector<int>> subsets(vector<int>& nums);

bool exist(vector<vector<char>>& board, string word);

#endif
