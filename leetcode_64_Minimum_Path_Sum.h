class Solution {

	int sumPathValue(vector<vector<int>>& grid, int x, int y)
	{
		if (grid.size() <= y || grid[0].size() <= x)
		{
			return INT_MAX;
		}

		int left = sumPathValue(grid, x + 1, y);

		int bottom = sumPathValue(grid, x, y + 1);

		if (INT_MAX == left && INT_MAX == bottom)
		{
			return grid[y][x];
		}
		else
		{
			grid[y][x] += std::min(left, bottom);
		}

		return grid[y][x];
	}


public:
	int minPathSum(vector<vector<int>>& grid) {

		return sumPathValue(grid, 0, 0);

	}
};