class Solution {

	bool isLetter(char c)
	{
		if ('a' <= c && c <= 'z')
		{
			return true;
		}
		else if ('A' <= c && c <= 'Z')
		{
			return true;
		}

		return false;
	}


public:
	string reverseOnlyLetters(string s) {

		int a = 0;
		int b = s.size() - 1;

		while (true)
		{

			while (false == isLetter(s[a]))
			{
				a++;

				if (b <= a)
				{
					break;
				}
			}

			while (false == isLetter(s[b]))
			{
				b--;

				if (b <= a)
				{
					break;
				}
			}

			if (a < b)
			{
				char t = s[a];
				s[a] = s[b];
				s[b] = t;

				a++;
				b--;
			}
			else
			{
				break;
			}
		}

		return s;

	}
};