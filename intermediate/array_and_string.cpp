#include "array_and_string.h"

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
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

// 尝试给出一种空间O(1)的方法
void setZeroes2(vector<vector<int>>& matrix) {
    if (matrix.size() == 0){
        return;
    }
    bool first_row = false, first_col = false;
    size_t row_cnt = matrix.size(), col_cnt = matrix[0].size();
    for (size_t i = 0; i < row_cnt; i++){
        if (matrix[i][0] == 0){
            first_col = true;
        }
    }
    for (size_t i = 0; i < col_cnt; i++){
        if (matrix[0][i] == 0){
            first_row = true;
        }
    }
    for (size_t i = 1; i < row_cnt; i++){
        for (size_t j = 1; j < col_cnt; j++){
            if (matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (size_t i = 1; i < row_cnt; i++){
        for (size_t j = 1; j < col_cnt; j++){
            if (matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if (first_col){
        for (size_t i = 0; i < row_cnt; i++){
            matrix[i][0] = 0;
        }
    }
    if (first_row){
        matrix[0].assign(col_cnt, 0);
    }
}


// 可用哈希表来提升速度
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<vector<int>, size_t> str_table;
    for (auto i : strs){
        vector<int> letter(26, 0);
        for (const auto &j : i){
            letter[j-'a']++;
        }
        auto ptr = str_table.find(letter);
        if (ptr == str_table.end()){
            str_table[letter] = ans.size();
            ans.push_back({i});
        }else{
            ans[ptr->second].push_back(i);
        }
    }
    return ans;
}

// 这道题很简单，用最长递增子串的思路就可以了。
int lengthOfLongestSubstring(string s) {
    int max_size = 0, temp = 0;
    size_t head = 0;
    for (size_t i = 0; i < s.size(); i++){
        size_t j;
        for (j = head; j < i; j++){
            if (s[j] == s[i]){
                break;
            }
        }
        if (j == i){
            temp++;
        }else{
            temp = i - j;
            head = j + 1;
        }
        max_size = max(max_size, temp);
    }
    return max_size;
}

