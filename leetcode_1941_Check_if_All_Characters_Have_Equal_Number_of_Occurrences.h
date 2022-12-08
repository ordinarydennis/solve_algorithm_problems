class Solution {
public:
	bool areOccurrencesEqual(string s) {

		std::unordered_map<char, int> m;

		for (int i = 0; i < s.size(); i++)
		{
			auto it = m.find(s[i]);
			
			if (m.end() == it)
			{
				m.emplace(s[i], 1);
			}
			else
			{
				it->second++;
			}
		}

		int c = m.begin()->second;

		for (const auto& [_, count] : m)
		{
			if (c != count)
			{
				return false;
			}
		}

		return true;

	}
};