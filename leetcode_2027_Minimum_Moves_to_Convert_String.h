class Solution {
public:
	int minimumMoves(string s) {

		int ret = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if ('X' == s[i])
			{
				ret++;
				i = i + 2;
			}
		}

		return ret; 
	}
};