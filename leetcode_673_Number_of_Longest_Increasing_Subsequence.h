
//[1,3,5,4,7]
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {

		int max = INT_MIN;

		int ret = 0;

		for (int a = 0; a < nums.size() - 1; a++)
		{
			int length = 1;

			int index = 1;

			for (int b = a; b < nums.size() - 1 && index < nums.size();)
			{
				if (nums[a] <= nums[b + index])
				{
					length++;
					b++;
					index = 1;
				}
				else
				{
					index++;
				}
			}

			if (max == length)
			{
				ret++;
			}
			else if (max < length)
			{
				ret = 1;
			}
		}

		return ret;
	}
};