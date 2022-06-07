class Solution {

	vector<int> sumList;

	bool dfs(vector<int>& matchsticks, int pos, int sum, int targetSize)
	{
		if (pos == matchsticks.size())
		{
			if (sumList[0] == targetSize && 
				sumList[1] == targetSize && 
				sumList[2] == targetSize)
			{
				return true;
			}

			return false;
		}

		for (int i = 0; i < 4; i++)
		{
			if (targetSize < sumList[i] + matchsticks[pos])
			{
				continue;
			}

			sumList[i] += matchsticks[pos];

			if (dfs(matchsticks, pos + 1, sum + matchsticks[pos], targetSize))
			{
				return true;
			}

			sumList[i] -= matchsticks[pos];

		}

		return false;
	}


public:
	bool makesquare(vector<int>& matchsticks) {

		int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

		if (0 != total % 4)
		{
			return false;
		}

		int targetSize = total / 4;

		sort(matchsticks.begin(), matchsticks.end());

		sumList.resize(4, 0);

		return dfs(matchsticks, 0, 0, targetSize);

	}
};
