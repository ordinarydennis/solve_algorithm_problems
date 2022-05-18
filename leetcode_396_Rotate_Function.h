class Solution {
public:
	int maxRotateFunction(vector<int>& nums) {

		int size = nums.size();

		int max = INT_MIN;

		for (int s = 0; s < size; s++)
		{
			int sum = 0;

			for (int i = 0; i < size; i++)
			{
				int index = s + i;

				if (size <= index)
				{
					index = index - size;
				}

				sum += (i) * nums[index];
			}

			max = std::max(max, sum);
		}

		return max;

	}
};