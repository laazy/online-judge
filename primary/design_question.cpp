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
    if (x < min){
        min = x;
    }   
    inner_stack.push(x);
}

void MinStack::pop(){
        
}

int MinStack::top(){
    
}

int MinStack::getMin(){
    
}

