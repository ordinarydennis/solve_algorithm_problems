class Solution {
public:
	int fib(int n) {

		int num1 = 0;
		int num2 = 1;
		

		if (n <= 1)
			return n == 0 ? num1 : num2;


		int ret = 0;

		for (int i = 2; i <= n; i++)
		{
			int tempNum1 = num1;

			num1 = num2;

			num2 = tempNum1 + num2;

			ret = num2;
		}

		return ret;
	}
};