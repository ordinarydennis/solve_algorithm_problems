
//top down
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

//bottom up
class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int max_row = triangle.size();

        vector<int> memo(triangle.back());

        for (int row = max_row - 2; 0 <= row; row--)
        {
            for (int i = 0; i <= row; i++)
            {
                memo[i] = triangle[row][i] + std::min(memo[i], memo[i + 1]);
            }

        }

        return memo[0];

    }
};
