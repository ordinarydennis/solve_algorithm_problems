class Solution {
public:
	string makeFancyString(string s) {

		if (s.size() < 3)
		{
			return s;
		}

		string ret;

		int i = 0;

		for (; i < s.size() - 2; i++)
		{
			if (s[i] == s[i + 1]  && s[i + 1] == s[i + 2] && s[i] == s[i + 2])
			{
				continue;
			}
			else
			{
				ret += s[i];
			}
		}

		if(0 < ret.size())
		{
			if (ret[ret.size() - 1] != s[i] || s[i] != s[i + 1] || ret[ret.size() - 1] != s[i + 1])
			{
				ret += s[i];
				ret += s[i + 1];
			}
		}
		else
		{
			ret += s[i];
			ret += s[i + 1];
		}

		return ret;

	}
};