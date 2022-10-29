class Solution {

	char convertLower(char c)
	{
		if ('a' <= c && c <= 'z')
		{
			return c;
		}
		int d = c - 'A';

		return 'a' + d;
	}


	bool isBadString(char c1, char c2)
	{
		char lc1 = convertLower(c1);
		char lc2 = convertLower(c2);

		if (lc1 != lc2)
		{
			return false;
		}
		
		if(lc1 == lc2 && c1 != c2)
		{
			return true;
		}

		return false;
	}


public:
	string makeGood(string s) {

		for (int i = 0; i < s.size() -1; i++)
		{
			if (isBadString(s[i], s[i + 1]))
			{
				s.erase(i + 1, 1);
				s.erase(i, 1);
				i = -1;

				if (0 == s.size())
				{
					break;
				}
			}
		}

		return s;
	}
};

