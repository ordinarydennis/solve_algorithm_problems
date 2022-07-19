class Solution {

	bool dfs(vector<vector<int>>& graph, int curNode, set<int>& path, map<int, bool>& checker)
	{
		const auto& nodeList = graph[curNode];

		if (nodeList.empty())
			return true;

		for (const int node : nodeList)
		{
			auto it = path.find(node);

			if (path.end() != it)
				return false;

			auto checkerIt = checker.find(node);

			if (checker.end() != checkerIt)
			{
				return false;
			}

			path.insert(node);

			if (false == dfs(graph, node, path, checker))
				return false;

			path.erase(node);
		}

		return true;
	}


public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

		vector<int> ret;

		ret.reserve(graph.size());

		map<int, bool> checker;

		for (int i = 0; i < graph.size(); i++)
		{
			set<int> path;

			if (dfs(graph, i, path, checker))
			{
				ret.push_back(i);
				//checker.emplace(i, true);
			}
			else
			{
				checker.emplace(i, false);
			}

		}

		return ret;

	}
};

