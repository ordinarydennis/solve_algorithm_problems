class Solution {


public:
	int nthUglyNumber(int n) {

		vector<int> v(n, 1);

		int index2 = 0;
		int index3 = 0;
		int index5 = 0;

		for (int i = 1; i < n; i++)
		{

			int num1 = v[index2] * 2;
			int num2 = v[index3] * 3;
			int num3 = v[index5] * 5;


			int min = std::min(
				num1,
				std::min(
					num2,
					num3
				)
			);


			if (num1 == min)
			{
				index2++;
			}

			if (num2 == min)
			{
				index3++;
			}

			if (num3 == min)
			{
				index5++;
			}

			v[i] = min;

		}

		return v[n - 1];
	}
};