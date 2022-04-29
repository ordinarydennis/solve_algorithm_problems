class Solution {
public:
	int maxProfit(vector<int>& prices) {

		//0 buy
		//1 sell
		//2 cooldown

		vector<int> dp(prices.size() , 0);

		for (int i = prices.size() - 1; 1 <= i; i--)
		{
			//
			if (prices[i - 1] < prices[i])
			{
				if (2 == dp[i])
				{
					dp[i - 1] = 1;
				}
				else
				{
					dp[i - 1] = 0;
					dp[i] = 1;
				}
			}
			else if (prices[i] < prices[i - 1])
			{
				if (1 == dp[i])
				{
					//cool buy
					dp[i - 1] = 2;
					dp[i] = 0;
				}
				else
				{
					//sell cool
					dp[i - 1] = 1;
					dp[i] = 2;
				}
			}
		}


	}
};