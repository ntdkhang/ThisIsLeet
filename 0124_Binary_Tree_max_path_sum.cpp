
// Definition for a binary tree node.
#include <algorithm>
#include <vector>
using namespace std;

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
    int global_max = INT_MIN; 

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return global_max;
    }

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l_max = 0, r_max = 0;

        if (root->left) {
            l_max = max(0, dfs(root->left));
        }
        if (root->right) {
            r_max = max(0, dfs(root->right));
        }

        global_max = max(global_max, l_max + r_max + root->val);
        return max(l_max + root->val, r_max + root->val);
        // return max(l_max, max(r_max, max(l_max + root->val, max(r_max + root->val, max(r_max + l_max + root->val, root->val)))));
    }

};
