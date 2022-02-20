class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		vector<vector<int>> ret;

		sort(intervals.begin(), intervals.end(), [](vector<int>& list1, vector<int>& list2) {
			return list1[0] < list2[0];
			});


		vector<int> v = intervals[0];
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] <= v[1])
			{
				if (v[1] <= intervals[i][1])
				{
					v[1] = intervals[i][1];
				}
			}
			else
			{
				ret.push_back(std::move(v));
				v = intervals[i];
			}
		}

		ret.push_back(std::move(v));

		return ret;
	}
};