class Solution {

	int ret = INT_MAX;

	void dfs(vector<vector<int>>& triangle, int depth, int pos, int sum)
	{
		if (triangle.size() - 1 <= depth)
		{
			ret = std::min(ret, sum + triangle[depth][pos]);
			return;
		}

		for (int i = pos; i <= pos + 1; i++)
		{
			if (triangle[depth].size() <= i)
			{
				break;
			}

			if (ret < sum + triangle[depth][i])
			{
				continue;
			}

			dfs(triangle, depth + 1, i, sum + triangle[depth][i]);
		}
	}


public:
	int minimumTotal(vector<vector<int>>& triangle) {

		dfs(triangle, 0, 0, 0);

		return ret;

	}
};