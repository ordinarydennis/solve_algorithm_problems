class Solution {

	std::vector<int> dp;

	bool isEven(int n)
	{
		return 0 == (n % 2);
	}

	int dfs(int n)
	{
		if (1 == n)
		{
			return 0;
		}

		if (INT_MAX != dp[n])
		{
			return dp[n];
		}

		//even
		if (isEven(n))
		{
			int retCount = dfs(n / 2) + 1;
			dp[n] = std::min(dp[n], retCount);
		}
		//odd
		else
		{
			for (int i = 0; i < 2; i++)
			{
				int n2 = (0 == i) ? n - 1 : n + 1;
				int retCount = dfs(n2) + 1;
				dp[n] = std::min(dp[n], retCount);
			}
		}

		return dp[n];
	}


public:
	int integerReplacement(int n) {

		if (1 == n)
		{
			return 0;
		}

		dp.resize(n + 1, INT_MAX);

		dfs(n);

		return dp[n];
	}
};