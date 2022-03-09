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

    int n = 0;
    int c = 0;
    int ret = 0;

    void dfs(TreeNode* root)
    {
        if (0 != ret)
        {
            return;
        }

        if (root->left)
        {
            dfs(root->left);
        }

        c++;

        if (n == c)
        {
            ret = root->val;
        }

        if (root->right)
        {
            dfs(root->right);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        n = k;

        dfs(root);

        return ret;
    }
};