class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int size = nums.size();

        if (1 == size)
            return 0;

        vector<int> dp(size, 0);

        int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            dp[0] += i * nums[i];
        }

        int max = dp[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] + sum - size * nums[size - i];
            max = std::max(max, dp[i]);
        }

        return max;
    }
};
