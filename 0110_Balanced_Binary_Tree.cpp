// Given a binary tree, determine if it is height-balanced


#include <algorithm>
#include <cstddef>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return false;
    }

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return std::max(height(root->left) + 1, height(root->right));

    }
};
