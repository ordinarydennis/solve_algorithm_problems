//Permutations with Repetition
//class Solution {
//
//    double factorial(double n)
//    {
//        double result = 1;
//        for (int i = 1; i <= n; i++)
//            result *= i;
//        return result;
//    }
//
//public:
//    int uniquePaths(int m, int n) {
//
//        m--;
//        n--;
//
//        return round(factorial(m + n) / (factorial(m) * factorial(n)));
//
//    }
//};

//The number of shortest distance cases.
//Time complexity : O(m * n)
//Space comlexity : O(m * n)
class Solution {

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int a =1; a < m; a++)
        {
            for (int b = 1; b < n; b++)
            {
                dp[a][b] = dp[a - 1][b] + dp[a][b - 1];
            }
        }

        return dp[m - 1][n - 1];

    }
};