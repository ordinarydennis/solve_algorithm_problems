
["1", "1", "0", "0", "0"], 
["1", "1", "0", "0", "0"], 
["0", "0", "1", "0", "0"], 
["0", "0", "0", "1", "1"]

class Solution {

	int checkStartPointR = -1;
	int checkStartPointC = -1;

	void findLand(vector<vector<char>>& grid, vector<vector<bool>>& landCheck, int r, int c, int& landCount)
	{

		if (grid.size() <= r || grid[0].size() <= c)
		{
			return;
		}

		if (r < 0 || c < 0)
		{
			return;
		}

		if (landCheck[r][c])
		{
			return;
		}

		if ('0' == grid[r][c])
		{
			return;
		}

		landCheck[r][c] = true;

		if (-1 == checkStartPointR && -1 == checkStartPointC)
		{
			checkStartPointR = r;
			checkStartPointC = c;
		}

		//주변 순회
		findLand(grid, landCheck, r, c + 1, landCount);
		findLand(grid, landCheck, r + 1, c, landCount);
		findLand(grid, landCheck, r, c - 1, landCount);
		findLand(grid, landCheck, r - 1, c, landCount);

		if (r == checkStartPointR && c == checkStartPointC)
		{
			landCount++;
			checkStartPointC = checkStartPointR = -1;
		}

		landCheck[r][c] = false;
	}


public:
	int numIslands(vector<vector<char>>& grid) {

		int landCount = 0;

		vector<vector<bool>> landCheck(grid.size(), vector<bool>(grid[0].size(), false));

		findLand(grid, landCheck, 0, 0, landCount);

		return landCount;
	}
};