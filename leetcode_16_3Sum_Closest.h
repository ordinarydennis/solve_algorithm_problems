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

				int result = target - sum;

				if (result < 0)
				{
					result *= -1;
				}

				if (result < minimum)
				{
					minimum = result;
					ret = sum;
				}

				if (target < sum)
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

