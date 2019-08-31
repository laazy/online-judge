#include "array_and_string.h"

/**
 * 考虑这样的方式：
 * 1. 先将输入数组排序
 * 2. 构造一张表，储存每个值最后一次出现的位置
 * 3. 两重循环遍历组合，但是这个循环保持如下特征，第 n 次与第 n+1 次
 *    迭代不同值
 * 4. 对每个组合，寻找其相反数所在位置，若其出现在两重循环位置以后则为
 *    合法解之一
 * 5. 收集所有这样的解，返回
 * 
 * 这个算法可以拓展到n个数之和，时间复杂度为O(2^(n-1))，空间复杂度为O(n)
 */ 
vector<vector<int>> threeSum(vector<int>& nums){
    if (nums.size() < 3){
        return {};
    }
    vector<vector<int>> ans;
    unordered_map<int, size_t> pos_table;
    size_t size = nums.size(), i = 0, j;
    int last_i, last_j;

    sort(nums.begin(), nums.end()--);
    for (size_t i = 0; i < size; i++){
        pos_table[nums[i]] = i;
    }

    while (i < size){
        // cut branch which is impossible
        j = i + 1;
        if (nums[i] > 0 || (j < size && nums[i] + nums[j] > 0)){
            break;
        }
        last_i = nums[i];
        while (j < size){
            last_j = nums[j];
            int left = 0 - nums[i] - nums[j];
            auto ptr = pos_table.find(left);
            if (ptr != pos_table.end() && ptr->second > j){
                ans.push_back({nums[i], nums[j], left});
            }
            for (; j < size && nums[j] == last_j; j++);
        }
        for (; i < size && nums[i] == last_i; i++);
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

/**
 * 这里用的O(n^2)算法，寻找中心点，然后从中间向两边扩张
 * 额外空间为O(n)
 */ 
string longestPalindrome(string s) {
    string str;
    for (const char &c : s){
        str.push_back('#');
        str.push_back(c);
    }
    str.push_back('#');

    int ans = 1;
    int center = 0, length = 0;
    size_t str_size = str.size();
    for (size_t i = 0; i < str_size; i++){
        int temp = 1;
        size_t j;
        for (j = 1; j < i && j + i < str_size; j++){
            if (str[i + j] == str[i - j]){
                temp += 2;
            }else{
                break;
            }
        }
        if (temp > ans){
            ans = temp;
            center = i;
            length = j;
        }
    }
    str = str.substr(center - length + 1, length * 2 - 1);
    for (auto ptr = str.begin(); ptr != str.end();){
        if (*ptr == '#'){
            ptr = str.erase(ptr);
        }else{
            ptr++;
        }
    }
    return str;
}

string longestPalindrome2(string s){
    string str;
    for (const char &c : s){
        str.push_back('#');
        str.push_back(c);
    }
    str.push_back('#');

    size_t str_size = str.size();
    // 此处长度为延伸出的长度，即长度为2n+1的回文串，此处值为n
    size_t pa_len[str_size];
    size_t center = 0, r_limit = 0;

    for (size_t i = 0; i < str_size; i++){
        size_t i_m = 2 * center - 1;
        pa_len[i] = r_limit > i ? min(r_limit - i, pa_len[i_m]) : 0;

        while (str[i + pa_len[i] + 1] == str[i - pa_len[i] - 1]){
            pa_len[i]++;
        }

        if (pa_len[i] + i > r_limit){
            center = i;
            r_limit = pa_len[i] - i;
        }
    }

    center = 0;
    for(const size_t &i : pa_len){
        if(i > center){
            center = i;
        }
    }

    str = str.substr(center, 2 * pa_len[center] + 1);
    for (auto ptr = str.begin(); ptr != str.end();){
        if (*ptr == '#'){
            ptr = str.erase(ptr);
        }else{
            ptr++;
        }
    }
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










