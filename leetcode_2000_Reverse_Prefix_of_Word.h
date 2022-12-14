class Solution {

	void swapString(string& s, int start, int end)
	{
		while (start < end)
		{
			char t = s[start];
			s[start] = s[end];
			s[end] = t;

			start++;
			end--;
		}
	}

public:
	string reversePrefix(string word, char ch) {

		for (int i = 0; i < word.size(); i++)
		{
			if (ch == word[i])
			{
				swapString(word, 0, i);
				break;
			}
		}

		return word;
	}
};