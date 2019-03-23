#ifndef TREE_AND_GRAPH_H
#define TREE_AND_GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
};

vector<int> inorderTraversal(TreeNode* root);

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

Node* connect(Node* root);

Node* connect2(Node* root);

int kthSmallest(TreeNode* root, int k);

#endif
