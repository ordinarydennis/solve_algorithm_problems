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

	int ret = true;

	int traversal(TreeNode* node)
	{
		if (nullptr == node)
		{
			return 0;
		}

		if (false == ret)
		{
			return 0;
		}

		int left = traversal(node->left);
		int right = traversal(node->right);

		if (1 < std::abs(left - right))
		{
			ret = false;
		}

		return std::max(left, right) + 1;
	}

public:
	bool isBalanced(TreeNode* root) {

		traversal(root);

		return ret;
	}
};