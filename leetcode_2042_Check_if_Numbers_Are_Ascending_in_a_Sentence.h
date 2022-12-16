class Solution {
public:
	bool areNumbersAscending(string s) {

		int max = 0;
		int n = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				int num = s[i] - '0';
				n *= 10;
				n += num;
			}
			else if (' ' == s[i] && 0 < n)
			{
				if (max < n)
				{
					max = n;
					n = 0;
				}
				else
				{
					return false;
				}
			}
		}

		if (0 < n && n <= max)
		{
			return false;
		}

		return true;
	}
};