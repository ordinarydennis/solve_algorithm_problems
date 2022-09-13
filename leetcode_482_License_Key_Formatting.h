class Solution {
public:
	string licenseKeyFormatting(string s, int k) {

		string ret;

		int size = 0; 

		for (int i = 0; i < s.size(); i++)
		{
			int ri = s.size() - 1 - i;

			if ('-' != s[ri])
			{
				if ('a' <= s[ri] && s[ri] <= 'z')
				{
					int g = s[ri] - 'a';
					s[ri] = 'A' + g;
				}

				ret.insert(0, 1, s[ri]);
				size++;

				if (size % k == 0 && 0 < ri)
				{
					ret.insert(0, 1, '-');
				}
			}

		}

		if ('-' == ret[0])
		{
			ret.erase(ret.begin());
		}
		
		return ret;

	}
};