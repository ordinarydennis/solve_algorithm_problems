class Solution {

	bool isCapitals(char c)
	{
		if ('A' <= c && c <= 'Z')
		{
			return true;
		}

		return false;
	}

public:
	bool detectCapitalUse(string word) {

		int capCount = 0;

		for (int i = 0; i< word.size(); i++)
		{ 
			if (isCapitals(word[i]))
			{
				capCount++;
			}
		}

		if (capCount == 0 || capCount == word.size())
		{
			return true;
		}

		if (1 == capCount && isCapitals(word[0]))
		{
			return true;
		}

		return false;

	}
};