class Solution {
public:
	int getLucky(string s, int k) {

		int sum = 0;

		for (int i = 0; i < s.size(); i++)
		{
			int n = s[i] - 'a' + 1;

			if (10 <= n)
			{
				sum += n / 10;
				sum += n % 10;
			}
			else
			{
				sum += n;
			}
		}

		for (int i = 1; i < k; i++)
		{
			int ret = 0;
			while (0 < sum)
			{
				ret += sum % 10;
				sum /= 10;
			}
			sum = ret;
		}

		return sum;
	}
};