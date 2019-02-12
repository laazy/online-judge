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
    return 0;// TODO
}

void rotate(vector<int>& nums, int k){
    vector<int> temp;
    temp.assign(nums.begin(), nums.end());
    size_t total = nums.size();
    for (size_t i = 0; i < total; i++){
        nums[(i + k) % total] = temp[i];
    }
}

bool containsDuplicate(vector<int>& nums) {
    set<int> hash_map;
    for (int i : nums){
        if (hash_map.find(i) == hash_map.end()){
            hash_map.insert(i);
        }else{
            return true;
        }
    }
    return false;
}

int singleNumber(vector<int>& nums){
    int ans = 0;
    for (int i : nums){
        ans = ans ^ i;
    }
    return ans;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    vector<int> *vec = &nums2;
    vector<int> *tar = &nums1;
    vector<int> ans;
    if (nums1.size() > nums2.size()){
        vec = &nums1;
        tar = &nums2;
    }
    for (int i : *vec){
        for (auto j = tar->begin(); j != tar->end(); j++){
            if ( i == *j){
                ans.push_back(i);
                tar->erase(j);
                break;
            }
        }
    }
    return ans;
}

vector<int> plusOne(vector<int>& digits) {
    bool flag = true;
    for (auto i = digits.rbegin(); i != digits.rend(); i++){
        if ( *i != 9){
            *i = *i + 1;
            flag = false;
            break;
        }else{
            *i = 0;
        }
    }
    if (flag){
        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }else{
        return digits;
    }
}

void moveZeroes(vector<int>& nums) {
    
}