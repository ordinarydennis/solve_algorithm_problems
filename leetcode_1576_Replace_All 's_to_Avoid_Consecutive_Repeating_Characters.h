class Solution {
public:
	string modifyString(string s) {

		for (int i = 0; i < s.size(); i++)
		{
			if ('?' == s[i])
			{
				int count = 0;

				char n = 'a' + count;

				if (0 <= i - 1 && i + 1 <= s.size() - 1)
				{
					while (n == s[i - 1] || n == s[i + 1])
					{
						count++;
						n = 'a' + count;
					}
				}
				else if (0 <= i - 1)
				{
					while (n == s[i - 1])
					{
						count++;
						n = 'a' + count;
					}
				}
				else
				{
					while (n == s[i + 1])
					{
						count++;
						n = 'a' + count;
					}
				}

				s[i] = n;
			}
		   
		}

		return s;

	}
};
