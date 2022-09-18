class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

		std::unordered_map<std::string, int> m;

		for (int i = 0; i < list1.size(); i++)
		{
			m[list1[i]] = i;
		}

		vector<string> ret;

		int min = INT_MAX;

		for (int i = 0; i < list2.size(); i++)
		{
			auto it = m.find(list2[i]);

			if (m.end() != it)
			{
				if (it->second + i == min)
				{
					ret.push_back(list2[i]);
				}
				else if (it->second + i < min)
				{
					min = it->second + i;
					ret.clear();
					ret.push_back(list2[i]);
				}
			}
		}

		return ret;

	}
};