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

	void traversal(TreeNode* root, std::string& str)
	{
		str += std::to_string(root->val);

		if (root->left)
		{
			str += "(";
			traversal(root->left, str);
			str += ")";
		}

		if (root->right)
		{
			if (nullptr == root->left)
			{
				str += "()";
			}

			str += "(";
			traversal(root->right, str);
			str += ")";
		}
	}


public:
	string tree2str(TreeNode* root) {

		std::string str;

		traversal(root, str);

		return str;
	}
};
