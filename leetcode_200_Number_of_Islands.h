class Solution {

	int count = 0;

	int maxR = 0;
	int maxC = 0;

	void findLand(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& isLand)
	{
		if ('0' == grid[r][c])
		{
			return;
		}

		if (isLand[r][c])
		{
			return;
		}

		isLand[r][c] = true;

		if (c + 1 < maxC)
		{
			findLand(grid, r, c + 1, isLand);
		}

		if (r + 1 < maxR)
		{
			findLand(grid, r + 1, c, isLand);
		}

		if (0 <= c - 1)
		{
			findLand(grid, r, c - 1, isLand);
		}

		if (0 <= r - 1)
		{
			findLand(grid, r - 1, c, isLand);
		}
	}


public:
	int numIslands(vector<vector<char>>& grid) {

		maxR = static_cast<int>(grid.size());
		maxC = static_cast<int>(grid[0].size());

		vector<vector<bool>> isLand(maxR, vector<bool>(maxC, false));

		for (int r = 0; r < maxR; r++)
		{
			for (int c = 0; c < maxC; c++)
			{
				if ('0' == grid[r][c])
				{
					continue;
				}

				if (isLand[r][c])
				{
					continue;
				}

				findLand(grid, r, c, isLand);

				count++;
			}
		}
		return count;
	}
};