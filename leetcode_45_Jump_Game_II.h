class Solution {

	int min_step = INT_MAX;

	void dfs(const vector<int>& nums, int index, int step)
	{
		if (nums.size() - 1 <= index)
		{
			if (step < min_step)
			{
				min_step = step;
			}
			return;
		}

		for (int i = 0; i <= nums[index]; i++)
		{
			if (0 == i)
			{
				continue;
			}

			dfs(nums, index + i, step + 1);
		}
	}

public:
	int jump(vector<int>& nums) {

		dfs(nums, 0, 0);

		return min_step;
	}
};