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

    int _targetSum = 0;

    bool ret = false;

    void dfs(TreeNode* root, int sum)
    {
        if (ret)
        {
            return;
        }

        if (nullptr == root->left && nullptr == root->right)
        {
            if (_targetSum == root->val + sum)
            {
                ret = true;
                return;
            }
        }

        if (root->left)
        {
            dfs(root->left, root->val + sum);
        }

        if (root->right)
        {
            dfs(root->right, root->val + sum);
        }
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (nullptr == root)
            return false;

        _targetSum = targetSum;

        dfs(root, 0);

        return ret;

    }
};