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
			return 1;
		}

		int left = traversal(node->left) + 1;
		int right = traversal(node->right) + 1;

		if(1 < std::abs(left - right))
		{

			ret = false;
		}

		return std::max(left, right);

	}



public:
	bool isBalanced(TreeNode* root) {

		traversal(root);

		return ret;
	}
};