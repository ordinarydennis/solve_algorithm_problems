class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int ySize = matrix.size();
        int xSize = matrix[0].size();

        bool fRow = false;
        bool fCol = false;

        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                if (0 == matrix[y][x])
                {
                    if (0 == y) fRow = true;
                    if (0 == x) fCol = true;

                    matrix[y][0] = 0;
                    matrix[0][x] = 0;
                }
            }
        }

        for (int y = 1; y < ySize; y++)
        {
            for (int x = 1; x < xSize; x++)
            {
                if (0 == matrix[0][x] || 0 == matrix[y][0])
                {
                    matrix[y][x] = 0;
                }
            }
        }

        if (fCol)
        {
            for (int y = 0; y < ySize; y++)
            {
                matrix[y][0] = 0;
            }
        }

        if (fRow)
        {
            for (int x = 0; x < xSize; x++)
            {
                matrix[0][x] = 0;
            }
        }

    }
};