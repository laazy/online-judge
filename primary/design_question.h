#ifndef DESIGN_QUESTION_H
#define DESIGN_QUESTION_H
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// shuffle an array
class Solution {
public:
    Solution(vector<int> nums);
    /** Resets the array to its original configuration and return it. */
    vector<int> reset();
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() ;
private:
    vector<int> array;
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack();
    
    void push(int x);
    
    void pop();
    
    int top();
    
    int getMin();
private:
    vector<int> inner_stack;
};

#endif
