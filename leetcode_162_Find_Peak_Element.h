class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		for (int i = 1; i < nums.size(); i++)
		{
			if (1 == i)
			{
				if (nums[i] <= nums[i - 1])
					return 0;
			}


			if (nums[i] <= nums[i - 1])
				continue;

			if (i + 1 < nums.size())
			{
				if (nums[i + 1] < nums[i])
				{
					return i;
				}
				else
				{
					continue;
				}
			}
		}

		return nums.size() - 1;

	}
};