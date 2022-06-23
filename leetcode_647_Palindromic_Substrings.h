class Solution {

	bool isPalindromic(const string& s)
	{
		for (int i = 0; i < s.size() / 2; i++)
		{
			int reversingIndex = s.size() - 1 - i;
			if (s[i] != s[reversingIndex])
			{
				return false;
			}
		}

		return true;
	}

public:
	int countSubstrings(string s) {

		int ret = 0;

		for (int a = 0; a < s.size() - 1; a++)
		{
			string str (1, s[a]);

			for (int b = a + 1; b < s.size(); b++)
			{
				str += s[b];

				if (isPalindromic(str))
				{
					ret++;
				}
			}
		}

		return ret + s.size();

	}
};