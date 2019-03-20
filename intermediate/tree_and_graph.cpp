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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root){
        return {};
    }

    vector<vector<int>> ans = {{}};
    queue<TreeNode*> odd_queue, even_queue, *cur_ptr = &odd_queue, *another_ptr = &even_queue;
    
    odd_queue.push(root);
    while (!odd_queue.empty() || !even_queue.empty()){
        if (!cur_ptr->empty()){
            TreeNode* node = cur_ptr->front();
            cur_ptr->pop();
            ans.back().push_back(node->val);
            if (node->left){
                another_ptr->push(node->left);
            }
            if (node->right){
                another_ptr->push(node->right);
            }
        }else{
            swap(cur_ptr, another_ptr);
            ans.push_back({});
        }
    }

    bool is_even = false;
    for (auto &i : ans){
        if (is_even){
            reverse(i.begin(), i.end());
        }
        is_even = !is_even;
    }

    return ans;
}