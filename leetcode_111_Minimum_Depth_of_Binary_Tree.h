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

    int ret = 0;

    void dfs(TreeNode* root, int depth)
    {
		depth++;

		if (ret < depth)
		{
			ret = depth;
		}

        if (root->left)
        {
            dfs(root->left, depth);
        }

        if (root->right)
		{
			dfs(root->right, depth);
        }


    }


public:
    int minDepth(TreeNode* root) {

        dfs(root, 0);

        return ret;

    }
};
 