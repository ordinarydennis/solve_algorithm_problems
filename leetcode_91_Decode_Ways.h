class Solution {

	std::vector<int> dp;

public:
	int numDecodings(const string& s)
	{
		dp.resize(s.size() + 1, 0);

		if ('0' == s[0])
		{
			return 0;
		}

		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= s.size(); i++)
		{
			if (s[i - 1] != '0')
			{
				dp[i] = dp[i - 1];
			}
			else
			{
				if (s[i - 2] != '1' && s[i - 2] != '2')
					return 0;
			}

			if (s[i - 2] == '1')
			{
				dp[i] += dp[i - 2];
			}
			else if (s[i - 2] == '2' && s[i - 1] <= '6')
			{
				dp[i] += dp[i - 2];
			}

		}

		return dp[s.length()];
	}
};


//Bottom-up dp.
class Solution {

public:
	int numDecodings(const string& s) {

		if ('0' == s[0])
		{
			return 0;
		}

		std::vector<int> dp(s.size() + 1, 0);

		dp[0] = 1;
		dp[1] = 1;

		for (int i = 1; i < s.size(); i++)
		{
			if ('0' != s[i])
			{
				dp[i + 1] = dp[i];
			}

			if ('1' == s[i - 1] || '2' == s[i - 1] && s[i] <= '6')
			{
				dp[i + 1] += dp[i - 1];
			}
		}

		return dp[s.size()];
	}
};


//top down dp with memoization.
class Solution {

	std::vector<int> memo;

	int Decoding(const string& s, int index)
	{
		if (s.size() - 1 == index)
		{
			return '0' != s[index] ? 1 : 0;
		}

		if (0 != memo[index])
		{
			return memo[index];
		}

		if ('0' != s[index])
		{
			memo[index] = Decoding(s, index + 1);
		}

		if ('1' == s[index] || '2' == s[index] && s[index + 1] <= '6')
		{
			memo[index] += Decoding(s, index + 2);
		}

		return memo[index];
	}

public:
	int numDecodings(const string& s) {

		if ('0' == s[0])
		{
			return 0;
		}

		memo.resize(s.size() + 1, 0);

		memo[s.size()] = 1;

		return Decoding(s, 0);

	}
};