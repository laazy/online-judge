#include "tree_question.h"
#include "../main.h"
#include "../util.h"

TreeNode* build_tree(vector<int> nums){
    if (nums.size() == 0){
        return nullptr;
    }
    queue<TreeNode*> temp;
    TreeNode *root = new TreeNode(nums[0]);
    temp.push(root);
    for (size_t i = 1; i < nums.size();){
        TreeNode *top = temp.front();
        temp.pop();
        if (nums[i] != 0){
            top->left = new TreeNode(nums[i]);
            temp.push(top->left);
        }
        i++;
        if (nums[i] != 0){
            top->right = new TreeNode(nums[i]);
            temp.push(top->right);
        }
        i++;
    }
    return root;
}

void test_maxDepth(){
    cout << maxDepth(build_tree({5,1,4,0,0,3,6})) << endl;
    cout << maxDepth(build_tree({2,1,3})) << endl;
}

void test_isValidBST(){
    cout << isValidBST(build_tree({5,1,4,0,0,3,6})) << endl;
    cout << isValidBST(build_tree({2,1,3})) << endl;
    cout << isValidBST(build_tree({10,5,15,0,0,6,20})) << endl;
}

void test_isValidBST2(){
    cout << isValidBST2(build_tree({5,1,4,0,0,3,6})) << endl;
    cout << isValidBST2(build_tree({2,1,3})) << endl;
    cout << isValidBST2(build_tree({10,5,15,0,0,6,20})) << endl;
}

int func(){
    test_isValidBST2();
    return 0;
}
