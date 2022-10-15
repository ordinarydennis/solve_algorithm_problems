class Solution {
public:
    int balancedStringSplit(string s) {

        int b = 0;

        int ret = 0;

        for (const char c : s)
        {
            if ('L' == c)
            {
                b++;
            }
            else
            {
                b--;
            }

            if (0 == b)
            {
                ret++;
            }
        }

        return ret;

    }
};