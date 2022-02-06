
//Brute force, Time Limit Exceeded
class Solution {
public:
    string longestPalindrome(string s) {

        int maxSize = 0;
        int beginIndex = 0;
        int endIndex = 0;

        for (int a = 0; a < s.size(); a++)
        {
            for (int b = a; b < s.size(); b++)
            {
                int isCorrect = true;
                int end = (b - a + 1) / 2;
                for (int c = 0; c < end; c++)
                {
                    int left = a + c;
                    int right = b - c;

                    if (s[left] != s[right])
                    {
                        isCorrect = false;
                        break;
                    }
                }

                if (isCorrect)
                {
                    if (maxSize < b - a + 1)
                    {
                        maxSize = b - a + 1;
                        beginIndex = a;
                        endIndex = b;
                    }
                }
            }
        }

        return std::move(string(s, beginIndex, endIndex - beginIndex + 1));
    }
};
