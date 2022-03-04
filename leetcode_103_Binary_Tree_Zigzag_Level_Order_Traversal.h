class Solution {

	unordered_map<int, vector<int>> map;

	void dfs(TreeNode* root, int level)
	{

		if (level % 2 == 1)
		{
			if (nullptr != root->right)
			{
				map[level].push_back(root->right->val);
			}

			if (nullptr != root->left)
			{
				map[level].push_back(root->left->val);
			}
		}
		else
		{
			if (nullptr != root->left)
			{
				map[level].push_back(root->left->val);
			}

			if (nullptr != root->right)
			{
				map[level].push_back(root->right->val);
			}
		}

		if (nullptr != root->left)
		{
			dfs(root->left, level + 1);
		}

		if (nullptr != root->right)
		{
			dfs(root->right, level + 1);
		}
	}

public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


		if (nullptr != root)
		{
			map[0].push_back(root->val);

			dfs(root, 1);
		}

		vector<vector<int>> ret;

		for (int i = 0; i < map.size(); i++)
		{
			ret.emplace_back(std::move(map[i]));
		}

		return ret;
	}

};