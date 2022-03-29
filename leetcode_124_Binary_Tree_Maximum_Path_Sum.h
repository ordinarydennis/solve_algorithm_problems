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

    int max = -1000;

    void dfs(TreeNode* root, int num)
    {
		if (max < root->val)
		{
			max = root->val;
		}

		int sum = sum + root->val + num;

		if (max < sum)
		{
			max = sum;
		}

		if (root->left)
		{
            dfs(root->left, sum);
			if (max < sum + root->left->val)
			{
				max = sum;
			}
		}
		
		if (root->right)
		{
            dfs(root->right, sum);
			if (max < sum + root->right->val)
			{
				max = sum;
			}
		}

		if (root->left && root->right)
		{
			if (max < sum + root->left->val + root->right->val)
			{
				max = sum;
			}
		}
    }


public:
    int maxPathSum(TreeNode* root) {

        dfs(root, 0);

        return max;
    }
};
//[-10,9,20,null,null,15,7]