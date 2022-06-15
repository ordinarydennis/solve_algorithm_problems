class Solution {

public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size(), 0));

		for (int row = 0; row < mat.size(); row++)
		{
			for (int column = 0; column < mat[0].size(); column++)
			{
				if (0 == mat[row][column])
				{
					ret[row][column] = 0;
					continue;
				}

				int nearest = INT_MAX;

				//аб
				if (0 < column)
				{
					if (0 == mat[row][column - 1])
					{
						ret[row][column] = 1;
						continue;
					}
					else
					{
						nearest = std::min(nearest, mat[row][column - 1] + 1);
					}
				}

				//ю╖
				if (0 < row)
				{
					if (0 == mat[row - 1][column])
					{
						ret[row][column] = 1;
						continue;
					}
					else
					{
						nearest = std::min(nearest, mat[row - 1][column] + 1);
					}
				}

				//©Л
				if (column < mat[0].size() - 1)
				{
					if (0 == mat[row][column + 1])
					{
						ret[row][column] = 1;
						continue;
					}
					else
					{
						nearest = std::max(nearest, mat[row][column + 1] + 1);
					}
				}

				//го
				if (row < mat.size() - 1)
				{
					if (0 == mat[row + 1][column])
					{
						ret[row][column] = 1;
						continue;
					}
					else
					{
						nearest = std::max(nearest, mat[row + 1][column] + 1);
					}
				}

				ret[row][column] = nearest;
			}
		}

		return ret;

	}
};