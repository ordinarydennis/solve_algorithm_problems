class Solution {
public:
	vector<string> removeAnagrams(vector<string>& words) {

		std::unordered_set<string> ss;

		vector<string> copy = words;

		for (auto& s : copy)
		{
			sort(s.begin(), s.end());
		}

		for (auto& s : copy)
		{
			ss.insert(s);
		}

		std::vector<string> ret;

		ret.reserve(ss.size());

		for (auto& s : words)
		{
			auto it = std::find(ss.begin(), ss.end(), s);

			if (ss.end() != it)
			{
				ret.emplace_back(*it);
			}
		}

		return ret;
	}
};