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

	std::queue<TreeNode*> q;

	void dfs(TreeNode* node)
	{
		if (nullptr == node)
		{
			return;
		}

		dfs(node->left);

		q.push(node);

		dfs(node->right);

	}

public:
	bool isValidBST(TreeNode* root) {

		dfs(root);

		while (1)
		{
			auto* node = q.front();

			q.pop();

			if (0 == q.size())
			{
				break;
			}

			if (q.front()->val <= node->val)
			{
				return false;
			}

		}

		return  true;

	}
};