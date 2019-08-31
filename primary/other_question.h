#ifndef OTHER_QUESTION_H
#define OTHER_QUESTION_H
#include <vector>
#include "iostream"
#include <stack>

using namespace std;

int hammingWeight(uint32_t n);

int hammingWeight2(uint32_t n);
// 还存在使用编译器内置的pop_count来计算的方法，抑或调用标准库

int hammingDistance(int x, int y);

uint32_t reverseBits(uint32_t n);

vector<vector<int>> generate(int numRows);

bool isValid(string s);

int missingNumber(vector<int> nums);

#endif
