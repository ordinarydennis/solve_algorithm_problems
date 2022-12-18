class Solution {

	bool isVowel(char c)
	{
		if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
		{
			return true;
		}

		return false;
	}

public:
	int countVowelSubstrings(string word) {

		std::unordered_set<char> s;

		int ret = 0;

		for (int a = 0; a < word.size(); a++)
		{
			s.clear();
			for (int i = a; i < word.size(); i++)
			{
				if (isVowel(word[i]))
				{
					s.insert(word[i]);

					if (5 <= s.size())
					{
						ret++;
					}
				}
				else
				{
					break;
				}
			}
		}

		return ret;
	}
};