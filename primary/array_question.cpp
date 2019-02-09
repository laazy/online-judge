#include "array_question.h"

int removeDuplicates(vector<int>& nums){
    vector<int>::iterator ptr = nums.begin();
    int head = nums[0];
    ptr++;
    for(; ptr != nums.end(); ){
        if(*ptr == head){
            nums.erase(ptr);
        }else{
            head = *ptr;
            ptr++;
        }
    }
    return nums.size();
}

int maxProfit(vector<int>& prices){
    return 0;
}

