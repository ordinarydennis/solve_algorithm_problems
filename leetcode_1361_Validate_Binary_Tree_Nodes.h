class Solution {

	bool ret = true;

	void dfs(int index, const std::vector<vector<int>>& mat, std::set<int>& chk)
	{
		if (chk.count(index))
		{
			ret = false;
			return;
		}

		chk.insert(index);

		if (0 == mat[index].size())
		{
			return;
		}

		const auto& list = mat[index];

		for (int n : list)
		{
			dfs(n, mat, chk);
		}
	}


public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

		std::vector<vector<int>> mat(n, vector<int>());

		std::set<int> chk;

		for (int i = 0; i < n; i++)
		{
			if (-1 != leftChild[i])
			{
				mat[i].push_back(leftChild[i]);
			}

			if (-1 != rightChild[i])
			{
				mat[i].push_back(rightChild[i]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (0 == chk.count(i))
			{
				dfs(i, mat, chk);
			}
		}
		
		if (chk.size() < n)
		{
			return false;
		}

		return ret;
	}
};
