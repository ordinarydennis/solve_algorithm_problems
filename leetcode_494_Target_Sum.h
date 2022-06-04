class Solution {

    int count = 0;

    void traversal(vector<int>& nums, int pos, int sum, int target)
    {
        if (pos == nums.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }

        traversal(nums, pos + 1, sum - nums[pos], target);
        traversal(nums, pos + 1, sum + nums[pos], target);

    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        traversal(nums, 0, 0, target);

        return count;
    }
};