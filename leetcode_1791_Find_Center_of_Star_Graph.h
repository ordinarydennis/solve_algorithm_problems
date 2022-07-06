class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {

		for (auto v1 : edges[0])
		{
			for (auto v2 : edges[1])
			{
				if (v1 == v2)
				{
					return v1;
				}
			}
			
		}

		return 0;

	}
};