class Solution {

	bool isVowel(char c)
	{
		if ('a' == c ||
			'e' == c ||
			'i' == c ||
			'o' == c ||
			'u' == c ||
			'A' == c ||
			'E' == c ||
			'I' == c ||
			'O' == c ||
			'U' == c
			)
		{
			return true;
		}

		return false;
	}

public:
	bool halvesAreAlike(string s) {

		int h = s.size() / 2;

		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < h; i++)
		{
			if (isVowel(s[i]))
			{
				count1++;
			}

		}

		for (int i = h; i < s.size(); i++)
		{
			if (isVowel(s[i]))
			{
				count2++;
			}
		}

		return count1 == count2;
	}
};