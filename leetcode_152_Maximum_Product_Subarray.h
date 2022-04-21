class Solution {
public:
	int maxProduct(vector<int>& nums) {

		vector<int> dp(nums.size(), 0);

		dp[nums.size() - 1] = nums.back();

		int max = dp[nums.size() - 1];

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			if (max < nums[i])
			{
				max = nums[i];
			}

			dp[i] = std::max(
				nums[i] * nums[i + 1],
				nums[i] * dp[i + 1]
			);
		}

		return std::max(dp[0], max);

	}
};