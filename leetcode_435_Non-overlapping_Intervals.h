class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {


		sort(intervals.begin(), intervals.end(),
			[](vector<int>& first, vector<int>& second) -> bool
			{
				if (first[0] == second[0])
				{
					return first[1] < second[1];
				}
				else
				{
					return first[0] < second[0];
				}


			});


		int min = intervals[0][0];
		int max = intervals[0][1];

		int ret = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			int start = intervals[i][0];
			int end = intervals[i][1];

			if (start < max)
			{
				ret++;
				continue;
			}

			max = end;

		}

		return ret;

	}
};