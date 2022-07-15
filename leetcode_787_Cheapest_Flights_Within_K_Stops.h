class Solution {

	int traversal(int src, int dst, int k, std::map<int, vector<vector<int>>>& pathInfo)
	{
		const vector<vector<int>>& pathList = pathInfo[src];

		int sum = 0;

		for (const auto& path : pathList)
		{
			int src = path[0];
			int dst2 = path[1];
			int cost = path[2];

			if (dst == dst2)
			{
				break;
			}

			if (0 == k)
			{
				break;
			}

			sum = traversal(dst2, dst, k - 1, pathInfo);

		}

		return sum;
	}


public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

		std::map<int, vector<vector<int>>> pathInfo;

		for (const auto& f : flights)
		{
			pathInfo[f[0]].emplace_back(f);
		}

		return traversal(src, dst, k + 1, pathInfo);
	}
};