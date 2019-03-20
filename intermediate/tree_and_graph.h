#ifndef TREE_AND_GRAPH_H
#define TREE_AND_GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root);

#endif
