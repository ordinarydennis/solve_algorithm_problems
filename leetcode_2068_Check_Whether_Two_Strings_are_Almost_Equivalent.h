class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {

		std::unordered_map<char, int> m1;
		std::unordered_map<char, int> m2;

		std::unordered_set<char> s;


		for (int i = 0; i < word1.size(); i++)
		{
			auto it = m1.find(word1[i]);
			if (m1.end() == it)
			{
				s.insert(word1[i]);
				m1.emplace(word1[i], 1);
			}
			else
			{
				m1[word1[i]]++;
			}
		}

		for (int i = 0; i < word2.size(); i++)
		{
			auto it = m2.find(word2[i]);
			if (m2.end() == it)
			{
				s.insert(word2[i]);
				m2.emplace(word2[i], 1);
			}
			else
			{
				m2[word2[i]]++;
			}
		}

		for (char c : s)
		{
			auto it1 = m1.find(c);
			auto it2 = m2.find(c);

			int n = (it1 == m1.end()) ? 0 : it1->second;
			int n2 = (it2 == m2.end()) ? 0 : it2->second;

			int r = n2 - n;

			if (3 < r || r < -3)
			{
				return false;
			}
		}

		return true;
	}
};