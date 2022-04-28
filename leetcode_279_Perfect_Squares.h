class Solution {

	int max = 0;

	void dfs(int n, int count)
	{

		for (int i = 4; i >= 2; i--)
		{
			int a = n - (i * i);

			if (a == 1)
			{
				count += 2;
				if (max < count)
				{
					max = count;
				}
				break;
			}

			if (a == 0)
			{
				//per
				count++;
				if (max < count)
				{
					max = count;
				}
				break;
			}
			else if (a < 0)
			{
				//fail
				continue;
			}
			else
			{
				//0 < a
				dfs(a, count + 1);
			}
		}
	}

public:
	int numSquares(int n) {

		if (1 == n || 2 == n || 3 == n)
		{
			return n;
		}

		dfs(n, 0);

		return max;

	}
};