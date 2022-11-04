class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {

		std::unordered_map<char, std::vector<int>> m;

		for (int i = 0; i < s.size(); i++)
		{
			const auto& it = m.find(s[i]);

			if (it == m.end())
			{
				m.emplace(s[i], std::vector<int> {i});
			}
			else
			{
				it->second.push_back(i);
			}
		}

		int max = 0;

		for (const auto& [c, list] : m)
		{
			if (1 == list.size())
			{
				continue;
			}

			int l = list[list.size() - 1] - list[0];
			max = std::max(l, max);

		}

		return max - 1;

	}
};