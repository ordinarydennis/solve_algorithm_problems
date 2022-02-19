class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		vector<vector<int>> ret;

		vector<int> iterval = intervals[0];

		for (int i = 1; i < intervals.size(); i++)
		{
			bool b = false;

			if (iterval[0] <= intervals[i][0] && intervals[i][1] <= iterval[1])
			{
				continue;
			}
			else if (iterval[0] <= intervals[i][0] && intervals[i][0] <= iterval[1])
			{
				if (iterval[1] <= intervals[i][1])
				{
					iterval[1] = intervals[i][1];
				}

				continue;
			}
			else if (intervals[i][0] <= iterval[0] && iterval[0] <= intervals[i][1])
			{
				iterval[0] = intervals[i][0];

				if (iterval[1] <= intervals[i][1])
				{
					iterval[1] = intervals[i][1];
				}

				continue;
			}

			ret.push_back(iterval);
			iterval = intervals[i];
		}

		ret.push_back(iterval);

		return ret;
	}
};