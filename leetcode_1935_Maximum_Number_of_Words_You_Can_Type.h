class Solution {
public:
	int canBeTypedWords(string text, string brokenLetters) {

		string w;

		int ret = 0;

		for (int i = 0 ; i <= text.size(); i++)
		{
			if (i == text.size()  || ' ' == text[i])
			{
				bool isFind = false;
				for (const char c : brokenLetters)
				{
					int index = w.find(c);
					if (index != string::npos)
					{
						isFind = true;
						break;
					}
				}

				if (false == isFind)
				{
					ret++;
				}

				w.clear();
			}
			else
			{
				w += text[i];
			}

		}

		return ret;
	}
};