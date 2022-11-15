class Solution {

	string convert(string s)
	{
		char pre = s[0];

		string ret;

		int count = 1;

		for (int i = 1; i < s.size(); i++)
		{
			if (pre == s[i])
			{
				count++;
			}
			else
			{
				ret += std::to_string(count);
				ret += pre;
				count = 1;
				pre = s[i];
			}
		}

		ret += std::to_string(count);
		ret += pre;

		return ret;
	}

	string dfs(int n)
	{
		if (1 == n)
		{
			return "1";
		}

		string ret = dfs(n - 1);

		return convert(ret);
	}

public:
	string countAndSay(int n) {

		return dfs(n);

	}
};