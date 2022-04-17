class Solution {

    vector<vector<int>> memo;

    int dp(vector<vector<int>>& triangle, int row, int index)
    {
        if (row == triangle.size() - 1)
        {
            return triangle[row][index];
        }

        if (INT_MIN != memo[row][index])
        {
            return memo[row][index];
        }

        memo[row][index] = triangle[row][index] + std::min(
            dp(triangle, row + 1, index),
            dp(triangle, row + 1, index + 1)
        );

        return memo[row][index];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        memo.resize(triangle.size(),
            vector<int>(triangle.size(), INT_MIN)
        );

        return dp(triangle, 0, 0);

    }
};