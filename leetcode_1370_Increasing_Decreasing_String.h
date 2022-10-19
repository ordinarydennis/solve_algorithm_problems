class Solution {
public:
	string sortString(string s) {

		std::sort(s.begin(), s.end());

		bool isASC = true;

		std::string ret;
		ret.reserve(s.size());

		while (s.size())
		{
			char lastC = s[0];
			ret += s[0];
			s.erase(0, 1);

			for (int i = 0; i < s.size(); )
			{
				if (lastC != s[i])
				{
					ret += s[i];
					lastC = s[i];
					s.erase(i, 1);
				}
				else
				{
					i++;
				}
				
			}

			if (0 == s.size())
			{
				break;
			}

			lastC = s[s.size() - 1];
			ret += s[s.size() - 1];
			s.erase(s.size() - 1, 1);

			for (int i = s.size() - 1; 0 <= i; i--)
			{
				if (lastC != s[i])
				{
					ret += s[i];
					lastC = s[i];
					s.erase(i, 1);
				}
			}

		}

		return ret;

	}
};