class Solution {
public:
	vector<int> getRow(int rowIndex) {

		vector<vector<int>> ret;

		for (int i = 0; i <= rowIndex; i++)
		{
			vector<int> row;

			for (int a = 0; a <= i; a++)
			{
				if (1 >= i)
				{
					row.push_back(1);
				}
				else
				{
					const auto& preRow = ret[i - 1];

					if (0 == a || i == a)
					{
						row.push_back(preRow[a - 1]);
					}
					else
					{
						row.push_back(preRow[a - 1] + preRow[a]);
					}
				}
			}

			ret.push_back(std::move(row));

		}


		return ret[rowIndex];

	}
};