class Solution {

    int count = 0;

    void traversal(vector<int>& nums, int pos, int sum, int target)
    {
        if (target == sum)
        {
            count++;
            return;
        }

        if (target < sum)
        {
            return;
        }

        if (nums.size() <= pos)
        {
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            int a = 1;

            if (i == 1)
            {
                a *= -1;
            }

            int value = a * nums[pos] + sum;

            traversal(nums, pos + 1, value, target);
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        traversal(nums, 0, 0, target);

        return count;
    }
};