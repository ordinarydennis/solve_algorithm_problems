class Solution {

	vector<vector<int>> ret;

	void dfs(vector<int>& nums, vector<int>& nList, int index)
	{
		if (nums.size() - 1 < index)
		{
			ret.push_back(nList);
			return;
		}

		for (int i = index; i < nums.size(); i++)
		{
			nList.push_back(nums[i]);
			dfs(nums, nList, i + 1);
			nList.pop_back();
		}
	}


public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<int> nList;

		ret.push_back({});

		for (auto n : nums)
		{
			ret.push_back({ n });
		}

		dfs(nums, nList, 0);

		return ret;
	}
};
