
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		vector<int> dp(nums.size(), 0);

		dp[nums.size() - 1] = 1;

		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				if (0 != dp[i + 1])
				{
					dp[i] = dp[i + 1] + 1;
				}
				else
				{
					for (int a = i + 2; a < nums.size(); a++)
					{
						if (nums[i] < nums[a])
						{
							dp[i] = dp[a] + 1;
							break;
						}
						else if (nums[i] == nums[a])
						{
							dp[i] = dp[a];
							break;
						}
					}
				}
			}
			else
			{
				for (int a = i + 2; a < nums.size(); a++)
				{
					if (nums[i] < nums[a])
					{
						dp[i] = dp[a] + 1;
						break;
					}
					else if (nums[i] == nums[a])
					{
						dp[i] = dp[a];
						break;
					}
				}
			}
		}

		sort(dp.begin(), dp.end());

		return dp[nums.size() - 1];

	}
};