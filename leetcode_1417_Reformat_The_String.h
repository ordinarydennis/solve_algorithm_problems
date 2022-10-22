class Solution {

	bool isAlphabet(char c)
	{
		return 'a' <= c && c <= 'z';
	}

public:
	string reformat(string s) {

		string sd;
		string ss;

		for (int i = 0; i < s.size(); i++)
		{
			if (isAlphabet(s[i]))
			{
				ss += s[i];
			}
			else
			{
				sd += s[i];
			}
		}

		if (0 == ss.size() || 0 == sd.size())
		{
			return "";
		}

		int si = 0;
		int di = 0;

		string ret;

		while (si < ss.size() || di < sd.size())
		{
			if (sd.size() < ss.size())
			{
				if (si < ss.size())
				{
					ret += ss[si];
					si++;
				}

				if (di < sd.size())
				{
					ret += sd[di];
					di++;
				}
			}
			else
			{
				if (di < sd.size())
				{
					ret += sd[di];
					di++;
				}

				if (si < ss.size())
				{
					ret += ss[si];
					si++;
				}
			}

		}

		return ret;

	}
};