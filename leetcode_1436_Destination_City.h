class Solution {
public:
	string destCity(vector<vector<string>>& paths) {

		std::unordered_map<string, string> pathMap;

		for (const auto& p : paths)
		{
			string source = p[0];
			string dest =p[1];
			pathMap[source] = dest;
		}

		string start = pathMap.begin()->first;

		while (1)
		{
			auto it = pathMap.find(start);
			if (pathMap.end() == it)
			{
				break;
			}

			//dest to source
			start = it->second;

		}

		return start;
	}
};

