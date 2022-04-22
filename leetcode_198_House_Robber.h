class Solution {
public:
	int rob(vector<int>& nums) {

		if (nums.size() <= 2)
		{
			return *std::max_element(nums.begin(), nums.end());
		}

		vector<int> dp(nums.size(), 0);

		dp[nums.size() - 1] = nums[nums.size() - 1];
		dp[nums.size() - 2] = nums[nums.size() - 2];

		for (int i = nums.size() - 3; 0 <= i; i--)
		{
			int max = 0;

			for (int k = i + 2; k < nums.size(); k++)
			{
				if (max < dp[k])
				{
					max = dp[k];
				}
			}

			dp[i] = nums[i] + max;
		}

		return std::max(dp[0], dp[1]);

	}
};
