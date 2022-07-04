
class Solution {

	int maxR = 0;
	int maxC = 0;

	vector<vector<bool>> checkRegion;

	int findRegion(vector<vector<char>>& board, int r, int c, vector<vector<int>>& regionList)
	{

		if (maxR <= r || r < 0)
			return 1;

		if (maxC <= c || c < 0)
			return 1;


		if ('X' == board[r][c])
			return 0;

		if (checkRegion[r][c])
			return 0;


		checkRegion[r][c] = true;

		regionList.emplace_back(std::move(vector<int> {r, c}));

		if (findRegion(board, r, c + 1, regionList))
		{
			return 1;
		}
		if (findRegion(board, r + 1, c, regionList))
		{
			return 1;
		}
		if (findRegion(board, r, c - 1, regionList))
		{
			return 1;
		}
		if (findRegion(board, r - 1, c, regionList))
		{
			return 1;
		}
		return 0;
	}


public:
	void solve(vector<vector<char>>& board) {

		maxR = static_cast<int>(board.size());
		maxC = static_cast<int>(board[0].size());

		checkRegion.resize(maxR);

		for (auto& r : checkRegion)
			r.resize(maxC);

		for (int r = 0; r < maxR; r++)
		{
			for (int c = 0; c < maxC; c++)
			{
				if ('X' == board[r][c])
					continue;

				vector<vector<int>> regionList;

				int result = findRegion(board, r, c, regionList);

				if (0 == result)
				{
					for (const auto& region : regionList)
					{
						board[region[0]][region[1]] = 'X';
					}
				}
			}
		}

	}
};