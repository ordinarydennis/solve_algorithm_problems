class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int start = 0;
		int end = nums.size() - 1;

		int ret = 0;

		while (1)
		{
			if (end - start == 1)
			{
				if (nums[start] == target)
				{
					ret = start;
				}
				else if (nums[start] < target && target < nums[end])
				{
					ret = start + 1;
				}
				else if (nums[end] == target)
				{
					ret = end;
				}
				else if (nums[end] < target)
				{
					ret = end + 1;
				}
				break;
			}
			else if (end == start)
			{
				if (nums[start] == target)
				{
					ret = start;
				}
				else if (nums[start] < target)
				{
					ret = start + 1;
				}
				else
				{
					ret = start - 1;
				}
				break;
			}

			int mid = (start + end) / 2;

			if (target == nums[mid])
			{
				ret = mid;
				break;
			}
			else if (target < nums[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		if (ret < 0)
		{
			ret = 0;
		}

		return ret;
	}
};