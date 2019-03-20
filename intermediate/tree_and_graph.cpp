#include "tree_and_graph.h"

vector<int> inorderTraversal(TreeNode* root){
    if (!root){
        return {};
    }
    stack<TreeNode*> inorder;
    vector<int> ans;
    
    TreeNode *node = root;
    do{
        while (node){
            inorder.push(node);
            node = node->left;
        }
        do{
            node = inorder.top();
            inorder.pop();
            ans.push_back(node->val);
        }while(!node->right && !inorder.empty());
        node = node->right;
    }while (node);
    return ans;
}