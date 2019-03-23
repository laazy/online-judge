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
    cout << ans << endl;
}

void test_connect(){
    Node root[7];
    for (int i = 0; i < 3; i++){
        root[i].val = i + 1;
        root[i].left = &root[i * 2 + 1];
        root[i].right = &root[i * 2 + 2];
        root[i].next = nullptr;
    }
    for (int i = 3; i < 7; i++){
        root[i].val = i + 1;
        root[i].left = nullptr;
        root[i].right = nullptr;
        root[i].next = nullptr;
    }
    Node* ans = connect(root);
    cout << ans << endl;
}

void test_connect2(){
    Node root[7];
    for (int i = 0; i < 3; i++){
        root[i].val = i + 1;
        root[i].left = &root[i * 2 + 1];
        root[i].right = &root[i * 2 + 2];
        root[i].next = nullptr;
    }
    for (int i = 3; i < 7; i++){
        root[i].val = i + 1;
        root[i].left = nullptr;
        root[i].right = nullptr;
        root[i].next = nullptr;
    }
    Node* ans = connect2(root);
    cout << ans << endl;
}

void test_kthSmallest() {
    TreeNode* root = build_tree({3,1,4,null,2});
    cout << kthSmallest(root, 1) << endl;
    root = build_tree({5,3,6,2,4,null,null,1});
    cout << kthSmallest(root, 3) << endl;
}

int func(){
    test_kthSmallest();
    return 0;
}
