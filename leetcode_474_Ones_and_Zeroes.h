class Solution {

    vector<int> dpZero;
    vector<int> dpOne;

    int ret = 0;

    void dfs(int pos, int m, int n, int sum0, int sum1, int count)
    {
        if (sum0 == m && sum1 == n)
        {
            ret = std::max(ret, count);
            return;
        }

        if (m < sum0 || n < sum1)
        {
            return;
        }

        for (int i = pos; i < dpZero.size(); i++)
        {
            dfs(i + 1, m, n, dpZero[i] + sum0, dpOne[i] + sum1, count + 1);
        }

    }


public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        dpZero.resize(strs.size(), 0);
        dpOne.resize(strs.size(), 0);

        for (int i = 0; i < strs.size(); i++)
        {
            for (int a = 0; a < strs[i].size(); a++)
            {

                if ('1' == strs[i][a])
                {
                    dpOne[i]++;
                }
                else
                {
                    dpZero[i]++;
                }

            }
        }



        dfs(0, m, n, 0, 0, 0);

        return ret;


    }
};