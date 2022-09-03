class Solution {
public:
	bool wordPattern(string pattern, string s) {

		unordered_map<char, string> m1;
		unordered_map<string, char> m2;

		string w;

		int pIndex = 0;
		
		for (int i = 0; i <= s.size(); i++)
		{
			if (' ' == s[i] || i == s.size())
			{
				auto it1 = m1.find(pattern[pIndex]);
				auto it2 = m2.find(w);

				if (it1 == m1.end() && it2 == m2.end())
				{
					m1.emplace(pattern[pIndex], w);
					m2.emplace(w, pattern[pIndex]);
				}
				else if (it1 != m1.end() && it2 != m2.end())
				{
					if (it1->first != it2->second)
					{
						return false;
					}
				}
				else
				{
					return false;
				}
				w = "";
				pIndex++;
			}
			else
			{
				w += s[i];
			}
		}

		return pattern.size() == (pIndex);

	}
};