class Solution {

	int remainEdge = 0;

	void dfs(int node, std::map<int, vector<int>>& paths, std::set<int>& check)
	{
		if (check.count(node))
		{
			remainEdge++;
			return;
		}

		check.insert(node);

		const auto& adjNodeList = paths[node];

		for (const auto& adjNode : adjNodeList)
		{
			dfs(adjNode, paths, check);
		}
	}

public:
	int makeConnected(int n, vector<vector<int>>& roads) {

		std::map<int, vector<int>> paths;

		std::set<int> check;

		for (const auto& nodes : roads)
		{
			paths[nodes[0]].push_back(nodes[1]);

		}

		int startNode = roads[0][0];

		const auto& adjNodeList = paths[startNode];

		check.insert(startNode);

		for (const auto& adjNode : adjNodeList)
		{
			dfs(adjNode, paths, check);
		}

		if (n == check.size())
		{
			return 0;
		}
		else
		{
			int count = n - check.size();

			if (count <= remainEdge)
			{
				return count;
			}
			else
			{
				return -1;
			}
		}

		return -1;
	}
};