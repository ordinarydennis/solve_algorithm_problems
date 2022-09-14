class Solution {

	void setDict(const std::string& s, int index, std::unordered_map<char, int>& dict)
	{
		for (const char c : s)
		{
			dict.emplace(c, index);
		}
	}

	char getSmallLetter(char c)
	{
		if ('A' <= c && c <= 'Z')
		{
			c = 'a' + c - 'A';
		}

		return c;
	}

public:
	vector<string> findWords(vector<string>& words) {

		std::unordered_map<char, int> dict;

		setDict("qwertyuiop", 0, dict);
		setDict("asdfghjkl", 1, dict);
		setDict("zxcvbnm", 2, dict);

		vector<string> ret;

		for (const auto& w : words)
		{
			int initIndex = dict[getSmallLetter(w[0])];
			bool check = true;
			for (int i = 1; i < w.size(); i++)
			{
				if (initIndex != dict[getSmallLetter(w[i])])
				{
					check = false;
					break;
				}
			}

			if (check)
			{
				ret.push_back(w);
			}
		}

		return ret;
	}
};