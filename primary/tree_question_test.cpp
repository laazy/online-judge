#include "tree_question.h"
#include "../main.h"
#include "../util.h"

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

void test_maxDepth(){
    cout << maxDepth(build_tree({5,1,4,null,null,3,6})) << endl;
    cout << maxDepth(build_tree({2,1,3})) << endl;
}

void test_isValidBST(){
    cout << isValidBST(build_tree({5,1,4,null,null,3,6})) << endl;
    cout << isValidBST(build_tree({2,1,3})) << endl;
    cout << isValidBST(build_tree({10,5,15,null,null,6,20})) << endl;
}

void test_isValidBST2(){
    cout << isValidBST2(build_tree({5,1,4,null,null,3,6})) << endl;
    cout << isValidBST2(build_tree({2,1,3})) << endl;
    cout << isValidBST2(build_tree({10,5,15,null,null,6,20})) << endl;
}

void test_isSymmetric(){
    cout << isSymmetric(build_tree({1,2,2,3,4,4,3})) <<endl;
    cout << isSymmetric(build_tree({1,2,2,null,3,null,3})) <<endl;    
}

void test_levelOrder(){
    print_matrix(levelOrder(build_tree({3,9,20,null,null,15,7})));
}

void test_sortedArrayToBST(){
    vector<int> nums1 = {-10,-3,0,5,9};
    print_matrix(levelOrder(sortedArrayToBST(nums1)));
    vector<int> nums2 = {0};
    print_matrix(levelOrder(sortedArrayToBST(nums2)));
    vector<int> nums3 = {0, 1};
    print_matrix(levelOrder(sortedArrayToBST(nums3)));
}

int func(){
    test_sortedArrayToBST();
    return 0;
}
