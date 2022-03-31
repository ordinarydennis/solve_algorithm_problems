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

	std::vector<int> ret;

public:
	vector<int> rightSideView(TreeNode* root) {

		if (nullptr == root)
		{
			return ret;
		}

		q.push(root);

		while (q.size())
		{
			int size = q.size();

			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				if (node->left)
				{
					q.push(node->left);
				}

				if (node->right)
				{
					q.push(node->right);
				}

				if (i == size - 1)
				{
					ret.push_back(node->val);
				}
			}
		}


		return ret;
	}
};