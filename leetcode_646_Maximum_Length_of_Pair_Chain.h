class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {

		sort(pairs.begin(), pairs.end(),
			[](vector<int>& pair1, vector<int>& pair2){

				return pair1[0] <= pair2[0];

			}
		);
	

		int max = 1;
		int ret = 1;
		
		for (int a = 0; a < pairs.size() - 1; a++)
		{
			for (int b = a + 1; b < pairs.size(); b++)
			{
				if (pairs[a][1] < pairs[b][0])
				{
					ret++;
				}
			}

			max = std::max(max, ret);

			ret = 1;

		}

		return max;

	}
};