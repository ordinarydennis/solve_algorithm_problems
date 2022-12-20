class Solution {

	bool isP(const std::string& s)
	{
		int f = 0;
		int l = s.size() - 1;

		while (f < l)
		{
			if (s[f] != s[l])
			{
				return false;
			}
			f++;
			l--;
		}

		return true;
	}

public:
	string firstPalindrome(vector<string>& words) {

		for (const auto& s : words)
		{
			if (isP(s))
			{
				return s;
			}
		}

		return false;
	}
};