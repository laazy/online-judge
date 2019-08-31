#ifndef STRING_QUESTION_H
#define STRING_QUESTION_H
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

void reverseString(vector<char>& s);

int reverse(int x);

int firstUniqChar(string s);

bool isAnagram(string s, string t);

bool isPalindrome(string s);

int myAtoi(string str);

int strStr(string haystack, string needle);

string countAndSay(int n);

string longestCommonPrefix(vector<string>& strs);

#endif