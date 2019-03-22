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

void test_zigzagLevelOrder(){
    print_matrix(zigzagLevelOrder(build_tree({3,9,20,null,null,15,7})));
    print_matrix(zigzagLevelOrder(build_tree({1,2,3,4,null,null,5})));
    print_matrix(zigzagLevelOrder(build_tree({1,2,3})));
}

void test_buildTree(){
    vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};
    TreeNode *ans = buildTree(pre, in);
}

int func(){
    test_buildTree();
    return 0;
}
