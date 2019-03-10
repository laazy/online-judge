#include "array_and_string.h"
#include "../util.h"
#include "../main.h"

#define null 0]

typedef vector<vector<int>> matrix_t;

void test_loop(){
    int limit = 20;
    int cnt = 0;
    for (int i = 0; i < limit; i++){
        for (int j = i + 1; j < limit; j++){
            for (int k = j + 1; k < limit; k++){
                cout << i << " " << j << " " << k << endl;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << limit * (limit - 1) * (limit - 2) / 3 / 2 << endl;
}

vector<vector<int>> test_combination_helper(vector<int> &nums){
    if (nums.size() == 1){
        return vector<vector<int>> {{nums[0]}};
    }
    int t = nums.back();
    nums.pop_back();
    vector<vector<int>> ans = test_combination_helper(nums);
    size_t size = ans.size();
    for (size_t i = 0; i < size; i++){
        ans.push_back(ans[i]);
        ans[i].push_back(t);
    }
    ans.push_back(vector<int> {t});
    return ans;
}

void test_combination(){
    vector<int> nums, ans;
    size_t limit = 3;
    for(; nums.size() < limit; nums.push_back(nums.size()));
    auto matrix = test_combination_helper(nums);
    print_matrix(matrix);
    cout << matrix.size() << endl;
}

void test_threeSum(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    print_matrix(threeSum(nums));
}

void test_setZeroes(){
    matrix_t matrix1 = {{1,1,1},
                        {1,0,1},
                        {1,1,1}};
    setZeroes(matrix1);
    print_matrix(matrix1);
    matrix_t matrix2 = {{0,1,2,0},
                        {3,4,5,2},
                        {1,3,1,5}};
    setZeroes(matrix2);
    print_matrix(matrix2);
}

void test_setZeroes2(){
    matrix_t matrix1 = {{1,1,1},
                        {1,0,1},
                        {1,1,1}};
    setZeroes2(matrix1);
    print_matrix(matrix1);
    matrix_t matrix2 = {{0,1,2,0},
                        {3,4,5,2},
                        {1,3,1,5}};
    setZeroes2(matrix2);
    print_matrix(matrix2);
}
void test_groupAnagrams(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = groupAnagrams(strs);
    for (const auto &i : ans){
        for (const auto &j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

void test_lengthOfLongestSubstring(){
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring("dvdf") << endl;
}

int func(){
    test_lengthOfLongestSubstring();
    return 0;
}
