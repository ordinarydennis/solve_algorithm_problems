class Solution {

	int strSize = 0;

	vector<string> ret;

	void dfs(int startIndex, int dotCount, std::string& str, const std::string& originS)
	{
		if (3 < dotCount)
		{
			return;
		}

		for (int i = 1; i <= 3; i++)
		{
			str.push_back(originS.substr(0, i + 1));

			if (3 == dotCount && strSize == (str.size() - dotCount))
			{
				ret.push_back(str);
				return;
			}

			str.push_back('.');

			dfs(i + 1, dotCount + 1, str);

			str.pop_back();
		}

	}


public:
	vector<string> restoreIpAddresses(string s) {

		strSize = s.size();

		dfs(0, 0, str, s);

		return ret;
	}
};