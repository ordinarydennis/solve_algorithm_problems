class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int pre = nums[0];

		int count = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (pre == nums[i])
			{
				nums[i] = INT_MIN;
				count++;
				continue;
			}

			pre = nums[i];
		}

		for (int i = 1; i < nums.size(); i++)
		{
			if (INT_MIN != nums[i])
			{
				continue;
			}

			for (int a = i + 1; a < nums.size(); a++)
			{
				if (INT_MIN != nums[a])
				{
					nums[i] = nums[a];
					nums[a] = INT_MIN;
					break;
				}
			}
		}

		return nums.size() - count;

	}
};