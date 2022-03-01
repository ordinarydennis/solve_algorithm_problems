//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		vector<int> dp(amount + 1, 10001);
//		int len = coins.size();
//		dp[0] = 0;
//
//		for (int value = 1; value <= amount; ++value)
//		{
//			for (int i = 0; i < len; ++i)
//			{
//				if (value - coins[i] >= 0)
//				{
//					dp[value] = min(dp[value], dp[value - coins[i]] + 1);
//				}
//			}
//		}
//
//		if (dp[amount] == 10001)
//			return -1;
//		return dp[amount];
//	}
//};

class Solution {

	int dfs(vector<int>& coins, int remains, vector<int>& rst)
	{
		if (remains < 0)
			return -1;

		if (remains == 0)
			return 0;

		if (rst[remains - 1] != 0)
			return rst[remains - 1];

		int min = INT_MAX;

		for (int coin : coins)
		{
			int temp = dfs(coins, remains - coin, rst);

			if (temp >= 0 && temp < min)
			{
				min = temp + 1;
			}
		}

		rst[remains - 1] = min == INT_MAX ? -1 : min;
		return rst[remains - 1];
	}

public:
	int coinChange(vector<int>& coins, int amount) {

		if (amount < 1) {
			return 0;
		}

		vector<int> rst(amount, 0);

		return dfs(coins, amount, rst);
	}
};