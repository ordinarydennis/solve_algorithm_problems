class Solution {

	int min = INT_MAX;


	void dfs(int n, int countOfA, int countOfAOnBoad, int operationCount, bool isCopyAll)
	{
		if (n < countOfA)
		{
			return;
		}

		if (n <= countOfA)
		{
			min = std::min(min, operationCount);
			return;
		}
		
		if (isCopyAll)
		{
			//paste
			dfs(n, countOfA + countOfAOnBoad, countOfAOnBoad, operationCount + 1, false);
		}
		else
		{
			//copy
			dfs(n, countOfA, countOfA, operationCount + 1, true);

			//paste
			dfs(n, countOfA + countOfAOnBoad, countOfAOnBoad, operationCount + 1, false);
		}
	}


public:
	int minSteps(int n) {

		dfs(n, 1, 0, 0, false);

		return min;


	}
};