class Solution {

	vector<vector<int>> ret;

	void dfs(int k, int n, int index, int sum, vector<int>& list)
	{
		if (k == list.size())
		{
			if (sum == n)
			{
				ret.push_back(list);
			}
		}

		for (int i = index; i < 10; i++)
		{

			if (n < sum + i)
			{
				break;
			}

			list.push_back(i);

			dfs(k, n, i + 1, sum + i, list);

			list.pop_back();

		}

	}


public:
	vector<vector<int>> combinationSum3(int k, int n) {

		vector<int> list;

		int sum = 0;
		int index = 1;

		dfs(k, n, index, sum, list);

		return ret;
	}
};