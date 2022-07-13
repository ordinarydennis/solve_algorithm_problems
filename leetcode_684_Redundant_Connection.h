class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {


		std::vector<bool> check(edges[0].size(), false);

		vector<int> ret;

		for (const auto& e : edges)
		{
			if (false == check[e[1]])
			{
				check[e[1]] = true;
			}
			else
			{
				ret.push_back(e[0]);
				ret.push_back(e[1]);
				break;
			}
		}


		return ret;
	}
};