class Solution {
public:
	int countSegments(string s) {

		int ret = 0;

		string w;

		for (int i = 0; i <= s.size(); i++)
		{
			if (' ' == s[i] || i == s.size())
			{
				if (w.size())
				{
					ret++;
					w = "";
				}
			}
			else
			{
				w += s[i];
			}
		}

		return ret;
	}
};