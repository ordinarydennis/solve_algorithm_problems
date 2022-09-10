class Solution {
public:
	int longestPalindrome(string s) {

		std::unordered_map<char, int> m;

		for (int i = 0; i < s.size(); i++)
		{
			if (m.count(s[i]))
			{
				m[s[i]]++;
			}
			else
			{
				m.emplace(s[i], 1);
			}
		}

		int ret = 0;

		for (const auto [c, n] : m)
		{
			if (n < 2)
				continue;

			ret += (0 == n % 2) ? n : n - 1;
		}

		return ret < s.size() ? ret + 1 : ret;

	}
};
