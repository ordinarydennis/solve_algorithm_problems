class Solution {
public:
	int minOperations(string s) {

		if (1 == s.size())
		{
			return 0;
		}

		char pre = s[0];

		int ret = 0;

		for (int i = 1; i < s.size(); i++)
		{
			if (pre == s[i])
			{
				s[i] = ('0' == pre) ? '1' : '0';
				ret++;
			}
			pre = s[i];
		}

		return ret;

	}
};