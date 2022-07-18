class Solution {

	vector<vector<int>> paths;

	void dfs(vector<vector<int>>& graph, int src, vector<int>& path)
	{
		vector<int>& nodeList = graph[src];

		if (graph.size() - 1 == src)
		{
			paths.push_back(path);
			return;
		}

		for (const int node : nodeList)
		{
			path.push_back(node);

			dfs(graph, node, path);

			path.pop_back();
		}

	}

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

		vector<int> path;

		path.push_back(0);

		dfs(graph, 0, path);

		return paths;

	}
};