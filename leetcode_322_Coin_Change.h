class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {

		if (0 == amount)
			return 0;

		sort(coins.begin(), coins.end(), greater<int>());

		int ret = 0;

		for (int i = 0; i < coins.size(); i++)
		{
			while (coins[i] <= amount)
			{
				amount -= coins[i];
				ret++;
			}

			if (amount <= 0)
			{
				break;
			}
		}

		if (0 == amount)
		{
			return ret;
		}
		else
		{
			return -1;
		}
	}
};