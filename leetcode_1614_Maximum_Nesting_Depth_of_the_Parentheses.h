class Solution {
public:
	int maxDepth(string s) {

		int r = 0;
		int ret = 0;
		int max = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if ('(' == s[i])
			{
				r++;
				max = std::max(r, max);
			}
			else if (')' == s[i])
			{
				r--;
			}

			if ('(' == s[i] || ')' == s[i])
			{
				if (0 == r)
				{
					ret = std::max(ret, max);
					max = 0;
				}
			}
		}

		return ret;

	}
};
