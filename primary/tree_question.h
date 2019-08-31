#ifndef TREE_QUESTION_H
#define TREE_QUESTION_H
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root);

bool isValidBST(TreeNode* root);

bool isValidBST2(TreeNode* root);

bool isSymmetric(TreeNode* root);

vector<vector<int>> levelOrder(TreeNode* root);

TreeNode* sortedArrayToBST(vector<int>& nums);

#endif