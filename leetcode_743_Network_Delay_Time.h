class Solution {

	int traversal(int start, int target, std::map<int, vector<vector<int>>>& pathMap)
	{
		const auto& it = pathMap.find(start);

		if (pathMap.end() == it)
		{
			return 0;
		}

		const auto& pathInfoMatrix = it->second;

		int time = 0;

		for (const auto& pathInfo : pathInfoMatrix)
		{
			int dest = pathInfo[1];
			int amount = pathInfo[2];

			if (dest == target)
			{
				return amount;
			}

			time = traversal(dest, target, pathMap);

			if (0 < time)
			{
				time += amount;
			}
		}

		return time;
	}


public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		std::map<int, vector<vector<int>>> pathMap;

		for (const auto& timeInfo : times)
		{
			pathMap[timeInfo[0]].emplace_back(timeInfo);
		}

		int time = traversal(k, n, pathMap);

		return 0 == time ? -1 : time;
	}
};