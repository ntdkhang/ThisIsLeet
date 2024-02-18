// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = p->val;
        int r = q->val;
        if (l>r) {
            swap(l, r);
        }
        TreeNode* currentNode = root;
        while (true) {
            if (currentNode->val >= l && currentNode->val <= r)
                return currentNode;
            else if (currentNode->val > r)
                currentNode = currentNode->left;
            else 
                currentNode = currentNode->right;
        }
        return nullptr;
    }
};
