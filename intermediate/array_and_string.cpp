#include "array_and_string.h"

/**
 * 思路是这样：
 * 构造一个数据结构set<set<int>> ans
 * 再构造一个map，里面存放所有数字的个数
 * 然后遍历输入数组，对每个二元组求和
 * 求其相反数与其组成的set是否已放入ans，已放入则跳过
 * 求其相反数是否存在，若存在是否用尽
 * 通过则放入
 * 
 */ 
vector<vector<int>> threeSum(vector<int>& nums){
    // set<unordered_multiset<int>> ans_set;
    vector<vector<int>> ans;
    // unordered_map<int, int> table;
    // for (const int& i : nums){
    //     auto ptr = table.find(i);
    //     if (ptr == table.end()){
    //         table[i] = 1;
    //     }else{
    //         ptr->second++;
    //     }
    // }

    // for (size_t i = 0; i < nums.size(); i++){
    //     for (size_t j = i + 1; j < nums.size(); j++){
    //         int k = 0 - nums[i] - nums[j];
    //         unordered_multiset<int> temp = {nums[i], nums[j], k};
    //         if (ans_set.find(temp) != ans_set.end() ||
    //             table.find(k) == table.end() || 
    //             table[k] - (nums[i] == k) - (nums[j] == k) < 0){
    //             continue;
    //         }
    //         ans_set.insert(temp);
    //     }
    // }
    // for (const auto &i : ans_set){
    //     vector<int> temp;
    //     for (const auto &j : i){
    //         temp.push_back(j);
    //     }
    //     ans.push_back(temp);
    // }

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
/**
 * 设f(n)为以第n个字符为结尾的最长递增子串长度，
 * s(n)为第n个字符为结尾的最长递增子串
 * A为原字符串
 * T(n, c)字符c在以第n个字符为结尾的最长递增子串中的绝对位置,也即距n最大的c字符位置
 *          /  f(n-1) + 1, A(n) 不属于 s(n-1)
 * f(n) = {
 *          \  n - T(n-1, A(n)), A(n) 属于 s(n-1)
 * 这个方法的时间复杂度是O(n^2),空间复杂度是O(1)
 * 但是如果考虑到字符串只有26个字母，即实际为有限字符，那么检查重复的时间复杂度为O(1)
 * 所以有限字符集下的时间复杂度是O(n)
 * 查重部分如果使用一个数组记录每个字符的最后一次出现位置，
 * 那么就可以一次查重，从而时间复杂度降低到O(n)，空间复杂度上升为O(m)，m为字符集大小
 */ 
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

string longestPalindrome(string s) {
    string str;
    for (const char &c : s){
        str.push_back('#');
        str.push_back(c);
    }
    str.push_back('#');

    return str;

}

/**
 * 
 * 这题很简单，只需要找最小的第二个数就可以了
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/29/array-and-strings/80/
 * 遍历发现满足条件：有一个数小于之前的第二个数，且大于之前数中的最小值，那么这个数就是新的第二个数
 * 如果有数大于第二个数，则符合题意
 */ 
bool increasingTriplet(vector<int>& nums) {
    int second = INT32_MAX, min_num = INT32_MAX;
    for(int &i : nums){
        if (i < min_num){
            min_num = i;
            continue;
        }
        if (i > second){
            return true;
        }
        if (second > i){
            second = i;
        }
    }
    return false;
}










