class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {

		vector<vector<int>> ret;

		int start = -1;
		int end = -1;

		int pre = s[0];

		for (int i = 1; i < s.size(); i++)
		{
			if (pre != s[i])
			{
				if (0 <= start && 0 < end)
				{
					if (2 <= end - start)
					{
						ret.push_back(std::vector<int>{start, end});
					}
				}

				start = -1;
				end = -1;
			}
			else
			{
				if (-1 == start)
				{
					start = i - 1;
				}
			}

			end = i;

			pre = s[i];
		}


		if (0 <= start && 0 < end)
		{
			if (2 <= end - start)
			{
				ret.push_back(std::vector<int>{start, end});
			}
		}

		return ret;

	}
};