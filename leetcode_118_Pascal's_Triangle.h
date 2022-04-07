class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector<vector<int>> ret;

		for (int i = 0; i < numRows; i++)
		{
			vector<int> list;

			list.reserve(i + 1);

			if (i <= 1)
			{
				for (int a = 0; a <= i; a++)
				{
					list.push_back(1);
				}
			}
			else
			{
				const auto& prelist = ret[i - 1];

				//012
				for (int a = 0; a <= i; a++)
				{
					int one = 0;
					
					if (0 == a)
					{
						one = prelist[a];
					}
					else
					{
						one = prelist[a - 1];
					}
					
					
					int two = 0;

					if (0 < a && a < i)
					{
						two = prelist[a];
					}
					
					list.push_back(one + two);
				}

			}

			ret.push_back(std::move(list));
		}

		return ret;
	}
};