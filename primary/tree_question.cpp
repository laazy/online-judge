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


bool isSymmetric(TreeNode* root) {
    if (!root){
        return true;
    }
    stack<TreeNode*> left, right;
    left.push(root->left);
    right.push(root->right);
    TreeNode *left_node, *right_node;
    while (!left.empty() || !right.empty()){
        left_node = left.top();
        right_node = right.top();
        left.pop();
        right.pop();
        if (!left_node ^ !right_node || (left_node && (left_node->val != right_node->val))){
            return false;
        }
        if (left_node && right_node){
            left.push(left_node->left);
            left.push(left_node->right);
            right.push(right_node->right);
            right.push(right_node->left);
        }
    }
    return true;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root){
        return vector<vector<int>> {};
    }
    queue<TreeNode*> out_tree, in_tree;
    if (root){
        out_tree.push(root);
    }
    TreeNode *cur;
    vector<vector<int>> ans;
    while (!out_tree.empty()){
        vector<int> temp;
        while (!out_tree.empty()){
            cur = out_tree.front();
            temp.push_back(cur->val);
            out_tree.pop();
            if (cur->left){
                in_tree.push(cur->left);
            }
            if (cur->right){
                in_tree.push(cur->right);
            }
        }
        ans.push_back(temp);
        out_tree.swap(in_tree);
    }
    return ans;
}

TreeNode* SAThelper(vector<int> &nums, size_t begin, size_t end){
    if (begin == end){
        return new TreeNode(nums[begin]);
    }
    size_t index = (begin + end) / 2;
    TreeNode *ans = new TreeNode(nums[index]);
    if (index != begin){
        ans->left = SAThelper(nums, begin, index - 1);
    }
    if (index != end){
        ans->right = SAThelper(nums, index + 1, end);
    }
    return ans;    
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()){
        return NULL;
    }
    TreeNode* ans = SAThelper(nums, 0, nums.size() - 1);
    return ans;
}