class Solution {

public:
    int longestPalindromeSubseq(string s) {

        int max = 0;

        for (int a = 0; a <= s.length() - 1; a++)
        {
            int count = 0;

            for (int b = a + 1; b <= s.length(); b++)
            {
                if (s[a] == s[b])
                {
                    count++;
                }
            }

            max = std::max(max, count);
        }

        return max + 1;
    }
};