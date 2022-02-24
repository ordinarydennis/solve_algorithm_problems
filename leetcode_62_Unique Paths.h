class Solution {

    int maxM = 0;
    int maxN = 0;

    int ret = 0;

    void dfs(int m, int n)
    {
        if (maxM <= m || maxN <= n)
        {
            return;
        }

        if (maxM - 1 == m && maxN - 1 == n)
        {
            ret++;
            return;
        }

        dfs(m, n + 1);

        dfs(m + 1, n);

    }

public:
    int uniquePaths(int m, int n) {

        maxM = m;
        maxN = n;

        dfs(0, 0);

        return ret;

    }
};