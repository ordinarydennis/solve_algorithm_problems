class Solution {
public:
	string truncateSentence(string s, int k) {

		int n = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (' ' == s[i])
			{
				n++;
			}

			if (n == k)
			{
				s.erase(i);
				break;
			}
		}

		return s;

	}
};