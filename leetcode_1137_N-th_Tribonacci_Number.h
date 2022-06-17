class Solution {
public:
	int tribonacci(int n) {

		int value0 = 0;
		int value1 = 1;
		int value2 = 1;

		if (0 == n)
		{
			return value0;
		}

		if (1 == n || 2 == n)
		{
			return value1;
		}

		if (3 == n)
		{
			return value2 + value1;
		}

		for (int i = 4; i <= n; i++)
		{
			int temp = value2 + value1 + value0;

			value0 = value1;
			value1 = value2;
			value2 = temp;

		}

		return value2 + value1 + value0;

	}
};