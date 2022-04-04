class Solution {

	vector<vector<int>> ret;

	void dfs(const vector<int>& nums, vector<int>& nList)
	{
		if (nums.size() <= nList.size())
		{
			ret.push_back(nList);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (nList.end() != find(nList.begin(), nList.end(), nums[i]))
				continue;

			nList.push_back(nums[i]);

			dfs(nums, nList);

			nList.pop_back();

		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {

		vector<int> nList;

		dfs(nums, nList);

		return ret;

	}
};