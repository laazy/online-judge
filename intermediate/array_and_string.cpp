#include "array_and_string.h"

vector<vector<int>> threeSum(vector<int>& nums){
    // sort
    unordered_map<int, pair<int, int>> hash_map;
    for (size_t i = 0; i < nums.size(); i++){
        auto ptr = hash_map.find(nums[i]);
        if (ptr == hash_map.end()){
            hash_map[nums[i]] = pair<int, int>{1, i};
        }else{
            hash_map[nums[i]].first++;
        }
    }
    vector<vector<int>> ans;
    for (size_t i = 0; i < hash_map.size(); i++){
        for (size_t j = i + 1; j < hash_map.size(); j++){
            auto ptr = hash_map.find((0 - nums[i] - nums[j]));
            if (ptr != hash_map.end() && ptr->second.second > j){
                ans.push_back(vector<int>{nums[i], nums[j], ptr->first});       
            }
        }
    }
    return ans;
}

// 空间复杂度为O(m + n)， 时间复杂度为O(mn)，比较naive
// 可以通过原地将行置为零并保存存在零的列数，这样可以把空间复杂度降到O(m)
// 适当的调整算法可以达到O(min(m,n))的程度
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0){
        return;
    }
    unordered_set<int> zero_row, zero_col;
    size_t row_cnt = matrix.size(), col_cnt = matrix[0].size();
    for (size_t i = 0; i < row_cnt; i++){
        for (size_t j = 0; j < col_cnt; j++){
            if (matrix[i][j] == 0){
                zero_row.insert(i);
                zero_col.insert(j);
            }
        }
    }
    for (size_t i = 0; i < row_cnt; i++){
        for (size_t j = 0; j < col_cnt; j++){
            if (zero_row.find(i) != zero_row.end() ||
                zero_col.find(j) != zero_col.end()){
                matrix[i][j] = 0;
            }
        }
    }
}

// 尝试用动态规划的方法给出一种空间O(1)的方法
void setZeroes2(vector<vector<int>>& matrix) {
    if (matrix.size() == 0){
        return;
    }
}

