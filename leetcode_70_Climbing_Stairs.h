class Solution {

public:
	int climbStairs(int n)
	{
		vector<int> steps(n, 0);

		steps[0] = 1;
		steps[1] = 2;

		for (int i = 2; i < n; i++)
		{
			steps[i] = steps[i - 2] + steps[i - 1];
		}

		return steps[n - 1];
	}

};

//top down with memoization
class Solution {

    int memo[45 + 1] = { 0, };

    int dp(int n)
    {

        if (1 >= n)
        {
            return 1;
        }

        if (0 != memo[n])
        {
            return memo[n];
        }

        return memo[n] = dp(n - 1) + dp(n - 2);
    }


public:
    int climbStairs(int n) {

        return dp(n);

    }
};