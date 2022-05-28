class Solution {

	vector<vector<int>> ret;

	void dfs(vector<int>& candidates, int target, int pos, int sum, vector<int>& list)
	{

		if (target == sum)
		{
			ret.push_back(list);
			return;
		}


		for (int i = pos; i < candidates.size(); i++)
		{
			if (target < candidates[i])
				return;

			if (target < sum + candidates[i])
				return;


			if (pos < i && candidates[i] == candidates[i - 1])
				continue;


			list.push_back(candidates[i]);

			dfs(candidates, target, i + 1, sum + candidates[i], list);

			list.pop_back();

		}

	}


public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		int sum = 0;

		vector<int> list;

		sort(candidates.begin(), candidates.end());

		dfs(candidates, target, 0, sum, list);

		return ret;


	}
};