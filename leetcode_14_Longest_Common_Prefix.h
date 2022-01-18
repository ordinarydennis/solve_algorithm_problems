class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		int i = 0;

		string ret;

		while (1)
		{
			char c = '\0';

			int a = 0;

			for (; a < strs.size(); a++)
			{
				const auto& str = strs[a];

				if (0 == str.size() || (str.size() - 1) < i)
				{
					break;
				}

				if ('\0' == c)
				{
					c = str[i];
					continue;
				}

				if (c != str[i])
				{
					break;
				}
			}

			if (a == strs.size())
			{
				ret.push_back(c);
				i++;
			}
			else
			{
				break;
			}
		}

		return ret;
	}
};
