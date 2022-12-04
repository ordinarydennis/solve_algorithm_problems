class Solution {

	int stoi(const string& s)
	{
		int n = 1;
		int ret = 0;

		for (int i = 0; i < s.size(); i++)
		{
			ret += s[i] - 'a';
			ret *= 10;
		}

		return ret;
	}

public:
	bool isSumEqual(string firstWord, string secondWord, string targetWord) {

		return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);

	}
};