#include "tree_question.h"

int maxDepth(TreeNode* root) {
    if (root == NULL){
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// O(N) 时间复杂度 O(N)空间复杂度 算法太丑
bool isValidBST(TreeNode* root){
    if (root == NULL){
        return true;
    }
    stack<TreeNode*> tree_stack;
    stack<long> low, high;
    tree_stack.push(root);
    low.push(INT64_MIN);
    high.push(INT64_MAX);
    long val, left, right;
    TreeNode* cur;  
    while (!tree_stack.empty()){
        cur = tree_stack.top();
        val = cur->val;
        left = low.top();
        right = high.top();
        if ( val <= left || val >= right){
            return false;
        }
        tree_stack.pop();
        low.pop();
        high.pop();
        if (cur->left != NULL){     
            tree_stack.push(cur->left);
            low.push(left);
            high.push(val);
        }
        if (cur->right != NULL){
            tree_stack.push(cur->right);
            low.push(val);
            high.push(right);
        }
    }
    return true;
}

// O(N) 时间复杂度 O(N)空间复杂度 很漂亮
bool isValidBST2(TreeNode* root){
    stack<TreeNode*> tree_stack;
    long val = INT64_MIN;
    while(!tree_stack.empty() || root){
        while (root){
            tree_stack.push(root);
            root = root->left;
        }
        root = tree_stack.top();
        tree_stack.pop();
        if (root->val <= val){
            return false;
        }
        val = root->val;
        root = root->right;
    }
    return true;
}
