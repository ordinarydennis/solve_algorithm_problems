class Solution {

	vector<vector<int>> dp;

	int sumPathValue(vector<vector<int>>& grid, int x, int y)
	{
		if (grid.size() <= y || grid[0].size() <= x)
		{
			return INT_MAX;
		}

		if (-1 != dp[y][x])
		{
			return dp[y][x];
		}

		auto left = sumPathValue(grid, x + 1, y);

		auto bottom = sumPathValue(grid, x, y + 1);

		if (INT_MAX == left && INT_MAX == bottom)
		{
			dp[y][x] = grid[y][x];
			return dp[y][x];
		}
		else
		{
			dp[y][x] = grid[y][x] + std::min(left, bottom);
		}

		return dp[y][x];
	}


public:
	int minPathSum(vector<vector<int>>& grid) {

		dp.resize(grid.size(), vector<int>(grid[0].size(), -1));

		return sumPathValue(grid, 0, 0);

	}
};