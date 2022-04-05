class Solution {

	int max = INT_MIN;
	
	void dfs(vector<int>& nums, int index)
	{
		if (nums.size() <= index)
		{
			return;
		}

		dfs(nums, index + 1);

		int sum = 0;

		for(int i = index; i < nums.size(); i++)
		{
			sum += nums[i];

			if (max < sum)
			{
				max = sum;
				v[i] = max;
			}
		}
	}


public:
	int maxSubArray(vector<int>& nums) {

		dfs(nums, 0);

		return max;
	}
};