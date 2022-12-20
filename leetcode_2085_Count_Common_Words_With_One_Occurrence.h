class Solution {
public:
	int countWords(vector<string>& words1, vector<string>& words2) {

		std::unordered_map<string, int> m1;
		std::unordered_map<string, int> m2;

		for (int i = 0 ; i < words1.size(); i++)
		{
			auto it = m1.find(words1[i]);

			if (m1.end() == it)
			{
				m1.emplace(words1[i], 1);
			}
			else
			{
				m1[words1[i]]++;
			}
		}

		for (int i = 0; i < words2.size(); i++)
		{
			auto it = m2.find(words2[i]);

			if (m2.end() == it)
			{
				m2.emplace(words2[i], 1);
			}
			else
			{
				m2[words2[i]]++;
			}
		}

		int ret = 0; 

		for (const auto& [s, c] : m1)
		{
			if (1 != c)
			{
				continue;
			}

			auto it = m2.find(s);

			if (m2.end() == it)
			{
				continue;
			}

			if (1 != it->second)
			{
				continue;
			}

			ret++;
		}

		return ret;

	}
};