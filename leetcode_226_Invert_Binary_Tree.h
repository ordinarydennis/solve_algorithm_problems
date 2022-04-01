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

public:
	TreeNode* invertTree(TreeNode* root) {

		if (nullptr == root)
		{
			return root;
		}

		std::vector<std::vector<TreeNode*>> vv;

		std::queue<TreeNode*> q;

		q.push(root);

		while (q.size())
		{
			int size = static_cast<int>(q.size());

			std::vector<TreeNode*> levelList;

			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				levelList.push_back(node);

				if (nullptr != node)
				{
					q.push(node->left);

					q.push(node->right);
				}

			}

			vv.push_back(std::move(levelList));

		}

		for (auto& v : vv)
		{
			int size = static_cast<int>(v.size());

			for (int i = 0; i < size / 2; i++)
			{
				auto* node1 = v[i];
				auto* node2 = v[size - i - 1];

				if (!node1 && !node2)
				{
					int temp = node1->val;
					node1->val = node2->val;
					node2->val = temp;
				}

			}

		}

		return root;
	}
};