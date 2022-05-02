class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		int maxRow = matrix.size();

		int maxColumn = (maxRow) ? matrix[0].size() : 0;

		vector<vector<int>> dp(
			maxRow + 1,
			vector<int>(maxColumn + 1, 0)
		);

		int max = 0;

		for (int row = 1; row <= maxRow; row++)
		{
			for (int column = 1; column <= maxColumn; column++)
			{
				if ('1' != matrix[row - 1][column - 1])
					continue;

				dp[row][column] = std::min(
					std::min(
						dp[row - 1][column],
						dp[row][column - 1]
					),
					dp[row - 1][column - 1]
				) + 1;

				max = std::max(max, dp[row][column]);

			}
		}

		return max * max;
	}
};

