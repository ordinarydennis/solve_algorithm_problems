class Solution {
public:
	int reverse(int x) {

		bool isM = false;

		if (x < 0)
		{
			if (INT_MIN == x)
			{
				return 0;
			}

			isM = true;
			x *= -1;
		}

		if (x < 10)
		{
			return x;
		}

		
		vector<char> v;
	
		while (true)
		{
			v.push_back((char)(x % 10));
			
			x = x / 10;

			if (x < 10)
			{
				v.push_back((char)(x));
				break;
			}
		}

		int ret = 0;

		for (const auto c : v)
		{
			if ((INT_MAX / 10) < ret )
			{
				return 0;
			}

			ret = ret * 10;

			ret = ret + (int)(c);

		}

		if (isM)
		{
			ret *= -1;
		}

		return ret;
	}
};