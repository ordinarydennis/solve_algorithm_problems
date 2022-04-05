class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int max = INT_MIN;

		for (int i = 0; i < nums.size(); i++)
		{
			int pre = 0;

			if (0 < i && 0 < nums[i - 1])
			{
				pre = nums[i - 1];
			}

			nums[i] = nums[i] + pre;

			if(max < nums[i])
			{
				max = nums[i];
			}
		}

		return max;
	}

};