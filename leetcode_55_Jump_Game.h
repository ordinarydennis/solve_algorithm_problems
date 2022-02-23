
//nums = [2,3,1,1,4]
class Solution {

	bool ret = false;
	vector<bool> indexList;

	bool dfs(const vector<int>& nums, int curIndex)
	{
		if (true == ret)
		{
			return true;
		}

		if (false == indexList[curIndex])
		{
			return false;
		}

		if (nums.size() - 1 == curIndex)
		{
			ret = true;
			return true;
		}

		if (nums.size() <= curIndex)
		{
			return false;
		}

		if (0 == nums[curIndex])
		{
			return false;
		}

		for (int i = 1; i <= nums[curIndex]; i++)
		{
			if (false == dfs(nums, curIndex + i))
			{
				indexList[curIndex + i] = false;
			}
		}

		return false;
	}


public:
	bool canJump(vector<int>& nums) {

		indexList.reserve(nums.size());
		indexList.assign(nums.size(), true);

		dfs(nums, 0);

		return ret;
	}
};