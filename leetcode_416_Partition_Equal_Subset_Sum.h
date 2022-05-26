class Solution {
public:
	bool canPartition(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 1; i++)
		{
			int subset1 = accumulate(nums.begin(), nums.end() - (1 + i), 0);
			int subset2 = accumulate(nums.end() - (1 + i), nums.end(), 0);

			if (subset1 == subset2)
			{
				return true;
			}
		}

		return false;

	}
};