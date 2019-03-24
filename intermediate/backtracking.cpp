#include "backtracking.h"

/**
 * 这道题同样可以用队列实现，相对用向量而言会节省一定的运行时空间
 * 事实上，每个向量在每次迭代时的空间大小也可以计算出来，所以可以预先开辟节省空间
 */ 
vector<string> letterCombinations(string digits){
    if (digits.empty()){
        return {};
    }
    vector<string> letter_array = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<int> input_digits;
    // convert input
    for (auto &i : digits){
        if (i >= '2' && i <= '9'){
            input_digits.push_back(i - '2');
        }
    }

    vector<string> last = {""}, cur;
    for (int i : input_digits){
        for (const auto &j : last){
            for (const auto &k : letter_array[i]){
                cur.push_back(j+k);
            }
        }
        last.swap(cur);
        cur.clear();
    }
    return last;
}

void gp_helper(string s, int n, int left, int right, vector<string> &ans){
    if (left > n || right > n){
        return;
    }
    if (left == right && left == n){
        ans.push_back(s);
        return;
    }
    if (left > right){
        gp_helper(s + ')', n, left, right + 1, ans);
    }
    if (left != n){
        gp_helper(s + '(', n, left + 1, right, ans);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    gp_helper("", n, 0, 0, ans);
    return ans;
}

/**
 * 这道题实际有三种做法： 
 * 第一种，可以用permute函数生成前m-1个数字的全排列，然后将第m个插入前m-1
 *  个全排列的空隙之中，这样可以生成前m个数字的全排列
 * 第二种，同样是生成m-1个数字的全排列，但是是将m个数字依此放置在固定位
 *  置，如头部或尾部，剩下m-1个数字生成全排列。
 * 第三种，记录当前已经使用的数字，每次遍历m个数字，去除其中一个，放置在
 *  临时变量中，然后递归进入继续遍历下m-1个数字，递归返回后补回原位。
 * 这三种方法，前两种是递归的思路，最后一种是回溯的思路
 * 这三种方法时间复杂度都是O(n!)，空间复杂度是O(n!)
 * 
 */
vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()){
        return {};
    }
    if (nums.size() == 1){
        return {{nums[0]}};
    }
    int temp, size_p = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < size_p; i++){
        temp = nums[0];
        nums.erase(nums.begin());
        auto low_ans = permute(nums);
        for (auto j : low_ans){
            j.push_back(temp);
            ans.push_back(j);
        }
        nums.push_back(temp);        
    }
    return ans;
}

/**
 * 此题有两种解法，
 * 一种是递归，取走第一个元素，对剩下元素生成子集，然后将子集复制一份，原来的一份添加第一个元素则为新子集
 * 第二种方法是迭代，用一个长整型代表集合中元素是否存在，从0~2^n，按照长整型生成对应集合
 * 
 */ 
vector<vector<int>> subsets(vector<int>& nums) {

}