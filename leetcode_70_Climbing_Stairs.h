class Solution {

	int count = 0;

	vector<int> v;

	bool dfs(int n, int step)
	{
		if (n == step)
		{
			count++;
			return true;
		}

		for (int i = 1; i <= 2; i++)
		{
			if (n < step + i)
			{
				continue;
			}

			if (dfs(n, step + i))
			{
				v[step + i]++;
			}
		}

		return false;
	}

public:
	int climbStairs(int n) {

		v.resize(n, 0);

		dfs(n, 0);

		return std::accumulate(v.begin(), v.end(), 0);

	}
};