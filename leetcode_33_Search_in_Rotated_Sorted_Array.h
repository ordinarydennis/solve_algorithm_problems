class Solution {
public:
	int search(vector<int>& nums, int target) {

		int ret = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (target == nums[i])
			{
				ret = i;
				break;
			}
		}

		return ret;
	}
};