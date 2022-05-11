class Solution {

	bool twoN(int num) {
		return (num & (num - 1)) == 0;
	}


public:
	vector<int> countBits(int n) {

		vector<int> dp(n + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			if (twoN(i))
			{
				dp[i] = 1;
			}
			else
			{
				dp[i] = dp[i - 1] + 1;
			}
		}

		return dp;

	}
};