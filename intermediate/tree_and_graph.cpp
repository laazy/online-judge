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

int vector_find(vector<int> &vec, int tar){
    int vec_size = vec.size();
    for (int i = 0; i < vec_size; i++){
        if (vec[i] == tar){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree_helper(vector<int>& preorder, int pre_b, vector<int>& inorder, int in_b, int in_e){
    if (in_b > in_e){
        return NULL;
    }
    TreeNode *cur = new TreeNode(preorder[pre_b]);
    int middle = vector_find(inorder, preorder[pre_b]);
    cur->left = buildTree_helper(preorder, pre_b + 1, inorder, in_b, middle - 1);
    cur->right = buildTree_helper(preorder, middle - in_b + 1 + pre_b, inorder, middle + 1, in_e);
    return cur;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()){
        return nullptr;
    }
    TreeNode *ans = buildTree_helper(preorder, 0, inorder, 0, inorder.size() - 1);
    return ans;
}

Node* connect(Node* root) {
    if (root == nullptr || root->left == nullptr){
        return root;
    }
    Node *left = root->left, *right = root->right;
    while (left != nullptr){
        left->next = right;
        left = left->right;
        right = right->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
}

Node* connect2(Node* root){
    if (root == nullptr || root->left == nullptr){
        return root;
    }
    Node *head = root, *cur = head;
    while(head->left){
        cur->left->next = cur->right;
        if (cur->next){
            cur->right->next = cur->next->left;
        }
        cur = cur->next;
        if (cur == nullptr){
            head = head->left;
            cur = head;
        }
    }
    return root;
}

TreeNode* kthSmallest_helper(TreeNode* root, int k, int &j){
    if (root == nullptr){
        return nullptr;
    }
    TreeNode* ans = kthSmallest_helper(root->left, k , j);
    if (ans != nullptr){
        return ans;
    }
    j++;
    if (k == j){
        return root;
    }
    ans = kthSmallest_helper(root->right, k, j);
    if (ans != nullptr){
        return ans;
    }
    // unreachable statement in logic
    return nullptr;
}

int kthSmallest(TreeNode* root, int k) {
    int j = 0;
    return kthSmallest_helper(root, k, j)->val;
}