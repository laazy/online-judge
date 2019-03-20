#include "tree_and_graph.h"
#include "../util.h"
#include "../main.h"

#define null 0

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

void test_inorderTraversal(){
    print_vec(inorderTraversal(build_tree({1,null,2,3})));
}

int func(){
    test_inorderTraversal();
    return 0;
}
