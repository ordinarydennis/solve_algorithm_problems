class Solution {

	char toUpper(char c)
	{
		char r = c;

		if ('a' <= c && c <= 'z')
		{
			int index = c - 'a';
			r = 'A' + index;
		}

		return r;
	}

	char toLower(char c)
	{
		char r = c;

		if ('A' <= c && c <= 'Z')
		{
			int index = c - 'A';
			r = 'a' + index;
		}

		return r;
	}

	void changeWord(string& s)
	{
		if (s.size() <= 2)
		{
			s[0] = toLower(s[0]);
			s[1] = toLower(s[1]);
			return;
		}

		s[0] = toUpper(s[0]);

		for (int i = 1; i < s.size(); i++)
		{
			s[i] = toLower(s[i]);
		}
	}



public:
	string capitalizeTitle(string title) {

		string w;
		string r;

		for (int i = 0; i < title.size(); i++)
		{
			if (' ' == title[i])
			{
				changeWord(w);

				r += w + " ";

				w.clear();
			}
			else
			{
				w += title[i];
			}
		}

		if (w.size())
		{
			changeWord(w);
			r += w;
		}

		return r;
	}
};