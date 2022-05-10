class Solution {

	int max = 0;

	bool dfs(int n, int sum, int product)
	{
		if (n == sum)
		{
			max = std::max(max, product);
			return true;
		}

		int index = n - sum;

		for (int i = 1; i < n; i++)
		{
			if (true == dfs(n, sum + i, product * i))
			{
				break;
			}
		}

		return false;
	}


public:
	int integerBreak(int n) {


		dfs(n, 0, 1);


		return max;
	}
};