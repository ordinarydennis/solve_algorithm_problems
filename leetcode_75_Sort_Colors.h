class Solution {
public:
	void sortColors(vector<int>& nums) {

		for (int a = 1; a < nums.size(); a++)
		{
			int cur = nums[a];

			int b = a - 1;

			for (; 0 <= b; b--)
			{
				if (cur < nums[b])
				{
					nums[b + 1] = nums[b];
				}
				else
				{
					nums[b + 1] = cur;
					break;
				}
			}

			if (b < 0)
			{
				nums[0] = cur;
			}

		}
	}
};