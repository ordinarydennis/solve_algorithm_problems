class Solution {

	string stringToInt(string s)
	{
		int ret = 0;

		for (int i = 0; i < s.size(); i++)
		{
			int n = s[i] - '0';
			ret += n;
		}

		return std::to_string(ret);
	}


public:
	string digitSum(string s, int k) {

		string str = std::move(s);

		while (k < str.size())
		{
			string sumStr;

			for (int i = 0; i < str.size();)
			{
				sumStr += stringToInt(str.substr(i, k));
				i += k;
			}

			str = sumStr;
		}

		return str;

	}
};