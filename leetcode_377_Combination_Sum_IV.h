class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {

		vector<int> dp(nums.size(), 0);
		
		for (int i = 0; i < nums.size(); i++)
		{
			int d = target % nums[i];

			if (d == 0)
			{
				dp[i] = target % nums[i];
			}
			else
			{
				if (0 != dp[d])
				{
					dp[i] = 1;
				}
			}

		}

		return std::accumulate(dp.begin(), dp.end(), 0);

	}
};