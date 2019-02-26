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
    for (int i = 1; i < nums.size();){
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

}

int func(){
    TreeNode *root = build_tree({5,1,4,0,0,3,6});
    return 0;
}
