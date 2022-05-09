class Solution {
public:
	bool isUgly(int n) {

		if (0 == n)
		{
			return false;
		}

		bool ret = true;

		while (1 != n)
		{
			if (0 == n % 2)
			{
				n /= 2;
				continue;
			}
			 
			if (0 == n % 3)
			{
				n /= 3;
				continue;
			}

			if (0 == n % 5)
			{
				n /= 5;
				continue;
			}

			ret = false;
			break;
		}

		return ret;
	}
};


class Solution {
public:
	bool isUgly(int n) {

		if (0 == n)
			return false;

		for (const auto prime : vector<short>{ 2, 3, 5 })
			while (0 == n % prime)
				n /= prime;

		return 1 == n;
	}
};