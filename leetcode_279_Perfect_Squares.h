class Solution {

    int min = INT_MAX;

    bool dfs(int n, int count, int remain)
    {
        if (remain < 0)
        {
            return false;
        }

        if (min < count)
        {
            return true;
        }

        if (0 == remain)
        {
            min = std::min(min, count);
            return true;
        }


        for (int i = n; 1 <= i; i--)
        {
            if (remain - (i * i) < 0)
            {
                continue;
            }

            bool result = dfs(i, count + 1, remain - (i * i));

            if (result)
            {
                break;
            }

        }


        return false;
    }


public:
    int numSquares(int n) {

        dfs(n, 0, n);

        return min;

    }
};