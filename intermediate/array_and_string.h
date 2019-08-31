#ifndef ARRAY_AND_STRING_H
#define ARRAY_AND_STRING_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

void setZeroes(vector<vector<int>>& matrix);

void setZeroes2(vector<vector<int>>& matrix);

vector<vector<string>> groupAnagrams(vector<string>& strs);

int lengthOfLongestSubstring(string s);

string longestPalindrome(string s);

string longestPalindrome2(string s);

bool increasingTriplet(vector<int>& nums);

#endif
