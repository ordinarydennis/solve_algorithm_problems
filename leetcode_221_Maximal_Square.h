class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		int max = 0;
		int my = matrix.size();
		int mx = matrix[0].size();
		
		for (int y = 0; y < my; y++)
		{
			for (int x = 0; x < mx; x++)
			{
				if (0 == matrix[y][x])
				{
					continue;
				}
				
				int count = 1;

				int yy = y;
				int xx = y;

				while (true)
				{
					if (my <= yy + 1 || mx <= xx + 1)
					{
						if (max < count)
						{
							max = count;
						}
						break;
					}

					if (matrix[yy + 1][xx] &&
						matrix[yy][xx + 1] &&
						matrix[yy + 1][xx + 1])
					{
						count++;
					}
					else
					{
						break;
					}
					yy++;
					xx++;

				}

				if (max < count)
				{
					max = count;
				}
			}
		}

		return max * 2;

	}
};