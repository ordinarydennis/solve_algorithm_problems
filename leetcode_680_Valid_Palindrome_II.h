class Solution {

	bool isPalindrome(const string& s)
	{

		int i = 0;
		int e = s.size() - 1;

		bool isOnePass = false;

		while (i < e)
		{

			if (s[i] == s[e])
			{
				i++;
				e--;
			}
			else
			{
				if (false == isOnePass)
				{
					if (isPalindrome(s.substr(i, e - i - 1) ||
						isPalindrome(s.substr(i + 1, e - i)
						)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}

		return true;

	}


public:
	bool validPalindrome(string s) {

		return isPalindrome(s);

	}
};
