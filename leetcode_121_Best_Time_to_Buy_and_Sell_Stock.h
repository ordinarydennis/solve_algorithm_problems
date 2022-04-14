class Solution {

public:
	int maxProfit(vector<int>& prices) {

		int start = 0;

		int last = prices.size() - 1;

		int max = INT_MIN;

		while (start <= last)
		{
			int b = prices[last] - prices[start];

			if (max < b)
			{
				max = b;
			}
		
			if (b < 0)
			{
				start++;
			}
			else
			{
				if (prices[start + 1] < prices[start])
				{
					start++;
				}
				
				if (prices[last] < prices[last - 1])
				{
					last--;
				}
			}
		}

		return max;

	}
};