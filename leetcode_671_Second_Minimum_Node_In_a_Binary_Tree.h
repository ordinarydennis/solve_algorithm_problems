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

    int min = 0;
    long ret = LONG_MAX;

    void dfs(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        if (min < root->val && root->val < ret)
        {
            ret = root->val;
        }
        else if (min == root->val)
        {
            dfs(root->left);
            dfs(root->right);
        }
    }

public:
    int findSecondMinimumValue(TreeNode* root) {

        min = root->val;

        dfs(root);

        return ret != LONG_MAX ? (int)ret : -1;
    }
};