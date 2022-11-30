class Solution {
public:
	string replaceDigits(string s) {

		string ret;

		for (int i = 0; i < s.size(); i++)
		{
			if (i % 2 == 1)
			{
				int n = s[i] - '0';
				ret += s[i - 1] + n;
			}
			else
			{
				ret += s[i];
			}
		}

		return ret;
	}
};