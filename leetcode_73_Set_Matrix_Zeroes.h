class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int ySize = matrix.size();

        int xSize = 0;
        if (0 < ySize)
        {
            xSize = matrix[0].size();
        }

        vector<pair<int, int>> pList;

        for (int a = 0; a < ySize; a++)
        {
            for (int b = 0; b < xSize; b++)
            {
                if (0 == matrix[a][b])
                {
                    pList.push_back({ a,b });
                }
            }
        }


        for (auto& p : pList)
        {
            for (int x = 0; x < xSize; x++)
            {
                matrix[p.first][x] = 0;
            }
            for (int y = 0; y < ySize; y++)
            {
                matrix[y][p.second] = 0;
            }
        }
    }
};