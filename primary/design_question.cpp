#include "design_question.h"

Solution::Solution(vector<int> nums){
    srand((unsigned)time(NULL));
    array = nums;
}

vector<int> Solution::reset(){
    return array;
}

vector<int> Solution::shuffle(){
    vector<int> ans = array;
    for (size_t i = array.size(); i != 0; i--){
        size_t ptr = (unsigned)rand() % i;
        swap(ans[ptr], ans[i - 1]);
    }
    return ans;
}

MinStack::MinStack(){

}

void MinStack::push(int x){
    inner_stack.push_back(x);
}

void MinStack::pop(){
    inner_stack.pop_back();
        
}

int MinStack::top(){
    return inner_stack.back();
}

int MinStack::getMin(){
    int ans = INT32_MAX;   
    for (int i : inner_stack){
        if (i < ans){
            ans = i;
        }
    } 
    return ans;
}

