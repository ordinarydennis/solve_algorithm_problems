class Solution {

	vector<vector<int>> ret;

	void dfs(vector<int>& candidates, int target, int pos, int sum, vector<int>& list)
	{

		for (int i = pos; i < candidates.size(); i++)
		{
			if (target < candidates[i])
			{
				break;
			}

			if (target < sum + candidates[i])
			{
				break;
			}

			list.push_back(candidates[i]);

			if (target == sum + candidates[i])
			{
				bool isFound = false;
				for (const auto& l : ret)
				{
					if (list == l)
					{
						isFound = true;
						break;
					}
				}

				if(false == isFound)
					ret.push_back(list);
			}
			else
			{
				dfs(candidates, target, i + 1, sum + candidates[i], list);
			}

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