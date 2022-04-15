class Solution {

    std::vector<int> dp;

public:
    int numDecodings(const string& s)
    {
        dp.resize(s.size() + 1, 0);

        if ('0' == s[0])
        {
            return 0;
        }

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); i++)
        {
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                if (s[i - 2] != '1' && s[i - 2] != '2')
                    return 0;
            }
            
            if (s[i - 2] == '1')
            {
                dp[i] += dp[i - 2];
            }
            else if (s[i - 2] == '2' && s[i - 1] <= '6')
            {
                dp[i] += dp[i - 2];
            }

        }

        return dp[s.length()];
    }
};
