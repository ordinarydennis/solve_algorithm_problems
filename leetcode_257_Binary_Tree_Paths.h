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

	void dfs(const TreeNode* node, string s, vector<string>& ret)
	{
		s += std::to_string(node->val);

		if (nullptr == node->left && nullptr == node->right)
		{
			ret.push_back(s);
			return;
		}

		if (node->left)
		{
			dfs(node->left, s + "->", ret);
		}

		if (node->right)
		{
			dfs(node->right, s + "->", ret);
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root) {

		string s;
		vector<string> ret;

		dfs(root, s, ret);

		return ret;

	}
};