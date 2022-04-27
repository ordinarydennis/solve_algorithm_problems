class Solution {

	vector<bool> dp;

	vector<int> factors = {2,3,5};

	bool dfs(int n)
	{
		if (dp[n])
		{
			return true;
		}

		for (const auto f : factors)
		{
			if (n % f == 0)
			{
				if (1 == n / f)
				{
					dp[n] = true;
					return true;
				}

				dfs(n / f);
			}
			else
			{
				return false;
			}
		}
		
		return false;
	}

	bool isPrime(int n)
	{
		if (dp[n])
		{
			return true;
		}

		return dfs(n);
	}

public:
	int nthUglyNumber(int n) {

		if (1 == n)
		{
			return 1;
		}

		dp.resize(1690, false);

		int count = 0;

		for (int i = 1; i <= n;)
		{
			if (isPrime(i))
			{
				i++;
			}
		}

		return dp[n];
	}
};