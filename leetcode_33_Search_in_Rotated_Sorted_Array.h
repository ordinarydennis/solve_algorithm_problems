class Solution {
public:
	int search(vector<int>& nums, int target) {

		int ret = -1;
		int zeroIndex = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (target == nums[i])
			{
				ret = i;
				if (zeroIndex != -1)
				{
					break;
				}
			}

			if (nums[i] == 0)
			{
				zeroIndex = i;
				if (-1 != ret)
				{
					break;
				}
			}
		}

		for (int i = 0; i < zeroIndex - 1; i++)
		{
			if (nums[i] >= nums[i+1])
			{
				return -1;
			}
		}

		for (int i = zeroIndex; i < nums.size() -1; i++)
		{
			if (nums[i] >= nums[i + 1])
			{
				return -1;
			}
		}

		return ret;
	}
};