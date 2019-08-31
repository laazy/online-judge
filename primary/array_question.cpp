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
    int ans = 0, size = prices.size();
    for (int i = 0; i < size - 1; i++){
        if (prices[i + 1] > prices[i]){
            ans += prices[i + 1] - prices[i];
        }
    }
    return ans;
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
    if (nums.size() == 0){
        return;
    }
    auto head = nums.begin();
    auto next = head;
    int temp;
    do {
        while (head != nums.end() && *head != 0){
            head++;
        }
        next = head;
        while (next != nums.end() && *next == 0){
            next++;
        }
        if(next != nums.end() && head != nums.end()){
            temp = *head;
            *head = *next;
            *next = temp;
        }
    } while (next != nums.end() && head != nums.end());
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map;
    auto itr = hash_map.begin();
    int size = nums.size();
    for (int i = 0; i < size; i++){
        // hash_map.insert_or_assign(nums[i], i);
        itr = hash_map.find(target - nums[i]);
        if (itr != hash_map.end()){
            return vector<int>{itr->second, i};
        }
        hash_map[nums[i]] = i;
    }
    return vector<int>{0, 0};
}

bool isValidSudoku(vector<vector<char>>& board){
    // 检查行，列
    unordered_map<char, int> row_map;
    unordered_map<char, int> col_map;
    unordered_map<char, int> small_map;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (row_map.find(board[i][j]) != row_map.end() ||
                col_map.find(board[j][i]) != col_map.end()){
                return false;
            }
            if (board[i][j] != '.'){
                row_map[board[i][j]] = 1;
            }
            if (board[j][i] != '.'){
                col_map[board[j][i]] = 1;
            }
        }
        row_map.clear();
        col_map.clear();
    }
    // 检查九宫格
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            vector<char> small_board = {
                board[3 * i][3 * j], board[3 * i][3 * j + 1], board[3 * i][3 * j + 2],
                board[3 * i + 1][3 * j], board[3 * i + 1][3 * j + 1], board[3 * i + 1][3 * j + 2],
                board[3 * i + 2][3 * j], board[3 * i + 2][3 * j + 1], board[3 * i + 2][3 * j + 2],
            };
            for (int k = 0; k < 9; k++){
                if (small_map.find(small_board[k]) != small_map.end()){
                    return false;
                }
                if (small_board[k] != '.'){
                    small_map[small_board[k]] = 1;
                }
            }
            small_map.clear();
        }
    }
    return true;
}

void rotateMatrix(vector<vector<int>>& matrix){
    int N = matrix.size() - 1;
    int row = (N + 1) / 2, col = (N + 2) / 2;
    int ele_x, ele_y, ele;
    int next_x, next_y;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            ele_x = i; 
            ele_y = j;
            ele = matrix[i][j];
            for (int k = 0; k < 4; k++){
                next_x = ele_y;
                next_y = N - ele_x;
                swap(matrix[next_x][next_y], ele);
                ele_x = next_x;
                ele_y = next_y;    
            }
        }
    }
}

// 改进版本
void rotateMatrix2(vector<vector<int>>& matrix){
    int N = matrix.size() - 1;
    for (int i = 0; i <= N ; i++){
        int j_li = N - i;
        for (int j = 0; j <= j_li; j++){
            swap(matrix[i][j], matrix[N - j][N - i]);
        }
    }
    int temp = (N + 1) / 2;
    for (int i = 0; i < temp; i++){
        matrix[i].swap(matrix[N - i]);
    }
}
