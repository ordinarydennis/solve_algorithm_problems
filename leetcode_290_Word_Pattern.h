class Solution {
public:
	bool wordPattern(string pattern, string s) {

		std::unordered_map<string, char> chk;
		std::unordered_set<char> chk2;

		string w;

		int pIndex = 0;

		for (int i = 0; i <= s.size(); i++)
		{
			if (' ' == s[i] || s.size() == i)
			{
				auto it = chk.find(w);

				if (chk.end() == it)
				{
					if (chk2.count(pattern[pIndex]))
					{
						return false;
					}

					chk.emplace(std::move(w), pattern[pIndex]);
					chk2.insert(pattern[pIndex]);
					pIndex++;
				}
				else
				{
					if (pattern[pIndex] != it->second)
					{
						return false;
					}
					else
					{
						pIndex++;
						w = "";
					}
				}
			}
			else
			{
				w += s[i];
			}

		}

		return chk.size() == chk2.size();

	}
};