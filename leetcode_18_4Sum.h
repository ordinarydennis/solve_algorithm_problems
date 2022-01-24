class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<int> iList;

		sort(nums.begin(), nums.end());

		dfs(nums, 0, target, iList);

		return ret;
	}


private:
	void dfs(const vector<int>& nums, int count, int target, vector<int>& iList)
	{
		if (4 <= iList.size())
		{
			int accum = accumulate(iList.begin(), iList.end(), 0);

			if (accum == target)
			{
				auto it = std::find(ret.begin(), ret.end(), iList);
				if (it == ret.end())
				{
					ret.push_back(iList);
				}
			}
			return;
		}

		for (int n = count; n < nums.size(); n++)
		{
			iList.push_back(nums[n]);
			dfs(nums, n + 1, target, iList);
			iList.erase(iList.end() - 1);
		}

	}

	vector<vector<int>> ret;

};