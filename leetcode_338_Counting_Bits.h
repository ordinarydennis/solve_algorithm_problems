class Solution {

	bool isTwoPowOfN(int num)
	{
		return (num & (num - 1)) == 0;
	}


public:
	vector<int> countBits(int n) {

		vector<int> dp(n + 1, 0);

		int twoPowIndex = 0;
		int nIndex = 0;

		for (int i = 1; i <= n; i++)
		{
			if (isTwoPowOfN(i))
			{
				dp[i] = 1;
				twoPowIndex = i;
				nIndex = 1;
			}
			else
			{
				dp[i] = dp[nIndex++] + dp[twoPowIndex];
			}
		}

		return dp;

	}
};