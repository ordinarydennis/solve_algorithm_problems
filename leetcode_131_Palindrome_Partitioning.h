class Solution {

	bool isPalindrome(const string& s)
	{
		bool ret = true;

		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				return false;
			}
		}

		return ret;
	}


public:
	vector<vector<string>> partition(string s) {

		vector<vector<string>> ret;

		vector<string> strList;

		for (int a = 0; a < s.size() - 1; a++)
		{
			string str;

			str += s[a];

			//strList.emplace_back(str);

			for (int b = a + 1; b < s.size(); b++)
			{
				str += s[b];
				if (true == isPalindrome(str))
				{
					strList.emplace_back(str);
				}
				else
				{
					break;
				}
			}

			ret.emplace_back(std::move(strList));
		}

		return ret;

	}
};