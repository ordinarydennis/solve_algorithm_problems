class Solution {
public:
	string largestOddNumber(string num) {

		for (int i = num.size() - 1; 0 <= i; i--)
		{
			int n = num[i] - '0';

			if (n % 2 != 0)
			{
				return num.substr(0, i + 1);
			}
		}

		return "";
	}
};