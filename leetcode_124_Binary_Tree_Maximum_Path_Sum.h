/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int max = INT_MIN;

    int dfs(TreeNode* root)
    {
        if (nullptr == root)
            return 0;

        int lmax = std::max(dfs(root->left), 0);

        int rmax = std::max(dfs(root->right), 0);

        max = std::max(max, root->val + lmax + rmax);

        return root->val + std::max(lmax, rmax);
    }

public:
    int maxPathSum(TreeNode* root) {

        dfs(root);

        return max;
    }
};