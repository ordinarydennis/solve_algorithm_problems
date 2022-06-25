class Solution {
public:
    int minSteps(int n) {

        int ans = 0;

        //when n is 2 or 3, the loop is not performed
        for (int d = 2; d * d <= n; d++) {

            //when copy & paste , no remaining number
            //when d = 2, cp (aa)
            //when d = 3, cpp (aaa)
            //when d = 4, cppp (aaaa)
            while (n % d == 0)
            {
                ans += d;
                n /= d;
            }
        }

        //when n is 10, 

        if (n != 1)
        {
            ans += n;
        }

        return ans;
    }
};