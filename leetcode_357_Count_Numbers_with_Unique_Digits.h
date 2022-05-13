class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {

		map<int, bool> dp;

		n = pow(10, n);

		for (int i = 0; i < n; i++)
		{
			auto it = dp.find(1);

			if (dp.end() == it)
			{
				dp.emplace(e, true);
			}

			n = n / 10;

		}

		return dp.size();

	}
};