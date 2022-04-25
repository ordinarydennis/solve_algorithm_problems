class Solution {
public:
	int rob(vector<int>& nums) {

		if (nums.size() <= 3)
		{
			return *max_element(nums.begin(), nums.end());
		}

		vector<int> dp(nums.size(), 0);

		dp[nums.size() - 1] = nums[nums.size() - 1];
		dp[nums.size() - 2] = nums[nums.size() - 2];

		for (int i = nums.size() - 3; 0 <= i; i--)
		{
			int max = 0;

			for (int a = i + 2; a < nums.size(); a++)
			{
				if (0 == i && a == nums.size() - 1)
				{
					continue;
				}

				if (max < nums[a])
				{
					max = nums[a];
				}
			}

			dp[i] = max + nums[i];
		}


		return std::max(dp[0], dp[1]);

	}
};