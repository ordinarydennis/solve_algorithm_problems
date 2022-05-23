class Solution {

	vector<vector<int>> ret;

	void dfs(vector<int>& candidates, int start, int sum, int target, vector<int>& list)
	{
		for (int i = start; i < candidates.size(); i++)
		{
			if (target < sum + candidates[i])
				break;

			list.push_back(candidates[i]);
			
			if (target == sum + candidates[i])
			{
				ret.push_back(list);
				list.pop_back();
				break;
			}

			dfs(candidates, i, sum + candidates[i], target, list);

			list.pop_back();
		}
	}


public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		
		std::sort(candidates.begin(), candidates.end());

		vector<int> list;
		
		int sum = 0;

		dfs(candidates, 0, sum, target, list);

		return ret;
	}
};