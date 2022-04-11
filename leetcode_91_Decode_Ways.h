class Solution {

	vector<string> list;

	void dfs(string& s, string str, int index)
	{
		for (int i = index; i < s.size(); i++)
		{
			if ('0' == s[i])
			{
				continue;
			}

			str += s[i];

			dfs(s, str, i + 1);

			if (1 < str.size())
			{
				list.push_back(str);
			}
		}
	}


public:
	int numDecodings(string s) {

		list.reserve(1000);

		string str;

		dfs(s, str, 0);

		return list.size();

	}
};