class Solution {

	vector<vector<int>> ret;

	void dfs(vector<int>& nums, vector<int>& nList, int index)
	{
		ret.push_back(nList);

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

		dfs(nums, nList, 0);

		return ret;
	}
};
