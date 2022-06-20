class Solution {

	int maxRow = 0;
	int maxColumn = 0;

	int numOfPath = 0;

	void dfs(int row, int column, int maxMove, int currentStep)
	{

		if (row < 0)
		{
			numOfPath++;
			return;
		}

		if (column < 0)
		{
			numOfPath++;
			return;
		}


		if (maxRow <= row)
		{
			numOfPath++;
			return;
		}

		if (maxColumn <= column)
		{
			numOfPath++;
			return;
		}

		if (maxMove <= currentStep)
		{
			return;
		}

		dfs(row, column + 1, maxMove, currentStep + 1);

		dfs(row + 1, column, maxMove, currentStep + 1);

		dfs(row, column - 1, maxMove, currentStep + 1);

		dfs(row - 1, column, maxMove, currentStep + 1);
	}


public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

		maxRow = m;
		maxColumn = n;

		dfs(startRow, startColumn, maxMove, 0);

		return numOfPath;
	}
};