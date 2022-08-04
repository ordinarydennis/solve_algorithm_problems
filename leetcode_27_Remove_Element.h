class Solution {
public:
	int removeElement(vector<int>& nums, int val) {

		int count = 0;

		vector<int> ret;

		ret.reserve(nums.size());

		for (const int e : nums)
		{
			if (e != val)
			{
				ret.push_back(e);
				count++;
			}
		}

		nums = ret;

		return count;

	}
};