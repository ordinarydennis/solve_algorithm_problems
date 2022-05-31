class Solution {

	vector<bool> dp;

	bool dfs(vector<int>& matchsticks, int pos, int sum, int targetSize)
	{
		for (int i = pos; i < matchsticks.size(); i++)
		{
			if (dp[i])
			{
				continue;
			}

			if (sum + matchsticks[i] == targetSize)
			{
				dp[i] = true;
				return;
			}

			if (dfs(matchsticks, i + 1, sum + matchsticks[i], targetSize))
			{
				dp[i] = true;
			}
		}
	}


public:
	bool makesquare(vector<int>& matchsticks) {

		dp.resize(matchsticks.size(), false);

		int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

		int targetSize = total / 4;

		sort(matchsticks.begin(), matchsticks.end());

		return dfs(matchsticks, 0, 0, targetSize);

	}
};