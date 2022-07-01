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
[1, null, 2, null, 3]
class Solution {

	int ret = true;
	TreeNode* root = nullptr;

	void traversal(TreeNode* node)
	{
		if (nullptr == node)
		{
			return;
		}

		if (nullptr == node->left && nullptr == node->right)
		{
			return;
		}

		if (root != node)
		{
			if (node->left && node->left->left)
			{
				ret = false;
				return;
			}
			if (node->left && node->left->right)
			{
				ret = false;
				return;
			}

			if (node->right && node->right->left)
			{
				ret = false;
				return;
			}
			if (node->right && node->right->right)
			{
				ret = false;
				return;
			}
		}


		traversal(node->left);
		traversal(node->right);

	}



public:
	bool isBalanced(TreeNode* root) {

		this->root = root;

		traversal(root);

		return ret;
	}
};