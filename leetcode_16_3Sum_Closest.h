[-1, 2, 1, -4]
1
e 2 
o -3

-4 -1 1 2 
// -3 = -3 + 1
//
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		sort(nums.begin(), nums.end());

		int size = nums.size();

		int minimum = 1000;

		int ret = 0;

		for (int i = 0; i < size; i++)
		{
			int l = i + 1;
			int r = size - 1;

			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];

				int result = sum - target;

				if (result < 0)
				{
					result *= -1;
				}

				if (result < minimum)
				{
					minimum = result;
					ret = sum;
				}

				while (l + 1 < size && nums[l] == nums[l + 1]) l++;
				while (0 < r && nums[r] == nums[r - 1]) r--;

				if (0 < result)
				{
					r--;
				}
				else
				{
					l++;
				}
			}
		}

		return ret;

	}
};