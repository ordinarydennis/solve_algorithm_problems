class Solution {
public:
	string thousandSeparator(int n) {

		if (0 == n)
		{
			return "0";
		}

		string ret;
		ret.reserve(n);

		int count = 0;

		while(n)
		{
			int k = n % 10;
			ret.push_back('0' + k);

			count++;

			n = n / 10;

			if (n && count % 3 == 0)
			{
				ret.push_back('.');
			}
		}

		std::reverse(ret.begin(), ret.end());

		return ret;

	}
};