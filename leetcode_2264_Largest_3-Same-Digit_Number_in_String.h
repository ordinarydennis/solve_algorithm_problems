class Solution {
public:
	string largestGoodInteger(string num) {

		string max;

		for (int i = 0; i < num.size(); i++)
		{
			auto s = num.substr(i, 3);

			if (s[0] == s[1] && s[1] == s[2])
			{
				if (max < s)
				{
					max = s;
				}

				if (num.size() - 1 <= i + 3)
				{
					break;
				}
			}
		}

		return max;

	}
};