class Solution {

	void dfs(int index, vector<int>& ret, int type, std::map<int, vector<int>>& pathMap)
	{
		if (ret[index])
		{
			return;
		}

		for (const int [i, paths] : pathMap)
		{
			dfs(i, ret, type + 1, pathMap);
		}
	}

public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

		vector<int> ret(n, 0);

		std::map<int, vector<int>> pathMap;

		for (const auto& path : paths)
		{
			pathMap[path[0]].push_back(path[1]);
		}

		int type = 0;

		for (const int[i, paths] : pathMap)
		{
			dfs(i, ret, type + 1, pathMap);
		}

		return ret;
	}
};