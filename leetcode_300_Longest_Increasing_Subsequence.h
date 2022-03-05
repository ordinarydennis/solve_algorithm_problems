class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);

        for (int a = 1; a < nums.size(); a++)
        {
            for (int b = 0; b < a; b++)
            {
                if (nums[b] < nums[a] && dp[a] < dp[b] + 1)
                {
                    dp[a] = dp[b] + 1;
                }
            }
        }
        
        return *std::max_element(dp.begin(), dp.end());

    }
};