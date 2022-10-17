class Solution {

	bool isPalindromic(std::string str)
	{

		int l = 0;
		int r = str.size() - 1;

		while (l < r)
		{
			if (str[l] != str[r])
			{
				return false;
			}
			l++;
			r--;
		}

		return true;
	}

public:
	int removePalindromeSub(string s) {

		int ret = 0;
		for (int i = 0; i < s.size();)
		{
			for (int a = 0;  a < s.size(); a++)
			{
				int size = s.size() - (i + a);

				if (1 == size)
				{
					ret++;
					i++;
					break;
				}

				if (isPalindromic(s.substr(i, size)))
				{
					ret++;
					i += size;
					break;
				}
			}
		}

		return ret;

	}
};