class Solution {

	int ret = 0;

	void dfs(int left, int right)
	{
		if (right < left)
		{
			return;
		}

		if (right == left)
		{
			return;
		}

		for (int a = left; a <= right; a++)
		{
			dfs(left, a - 1);
			dfs(a + 1, right);
			ret++;
		}
	}

public:
	int numTrees(int n) {

		dfs(1, n);

		return ret;

	}
};