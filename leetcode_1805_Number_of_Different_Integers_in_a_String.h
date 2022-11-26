class Solution {
public:
	int numDifferentIntegers(string word) {

		bool isStart = false;

		std::unordered_set<string> ss;

		string s;

		for (int i = 0; i < word.size(); i++)
		{
			if ('a' <= word[i] && word[i] <= 'z')
			{
				if (isStart)
				{
					ss.emplace(s);
					s.clear();
					isStart = false;
				}
				continue;
			}

			if ('0' == word[i] && false == isStart)
			{
				if (i < word.size() - 1)
				{
					if ('a' <= word[i + 1] && word[i + 1] <= 'z')
					{
						s += word[i];
						isStart = true;
					}
				}
				else if (i == word.size() - 1)
				{
					s += word[i];
					isStart = true;
				}
				continue;
			}

			s += word[i];
			isStart = true;

		}

		if (isStart)
		{
			ss.emplace(s);
		}

		return ss.size();

	}
};