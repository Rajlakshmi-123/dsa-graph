/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int target) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return target == root->val;

        return dfs(root->left, target - root->val) ||
               dfs(root->right, target - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};