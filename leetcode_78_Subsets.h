class Solution {

	vector<vector<int>> ret;


	void dfs(vector<int>& nums, vector<int>& list, int index)
	{
		ret.push_back(list);

		for (int i = index; i < nums.size(); i++)
		{
			list.push_back(nums[i]);
			dfs(nums, list, i + 1);
			list.pop_back();
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<int> list;

		dfs(nums, list, 0);

		return ret;

	}
};
