class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, vector<string>> m;

		for (auto& str : strs)
		{
			string str2 = str;
			sort(str2.begin(), str2.end());

			m[str2].push_back(std::move(str));
		}

		vector<vector<string>> ret;

		for (auto& [_, sl] : m)
		{
			ret.push_back(std::move(sl));
		}

		return ret;

	}
};