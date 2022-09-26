class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {

		std::string word;

		std::unordered_map<string, int> m;

		std::string ret;

		int max = INT_MIN;

		std::vector symbols = {' ', ',', '.', '!', '?',';','\''};

		for (int i = 0; i <= paragraph.size(); i++)
		{
			auto fIt = std::find(symbols.begin(), symbols.end(), paragraph[i]);

			if (fIt != symbols.end() || i == paragraph.size())
			{
				if (word.empty()) 
					continue;

				auto it = std::find(banned.begin(), banned.end(), word);

				if (it != banned.end())
				{
					word.clear();
					continue;
				}

				if (m.count(word))
				{
					m[word]++;
				}
				else
				{
					m[word] = 1;
				}

				if (max < m[word])
				{
					ret = word;
					max = m[word];
				}
				word.clear();
			}
			else
			{
				if ('A' <= paragraph[i] && paragraph[i] <= 'Z')
				{
					paragraph[i] = 'a' + (paragraph[i] - 'A');
				}
				word += paragraph[i];
			}
		}

		return ret;
	}
};