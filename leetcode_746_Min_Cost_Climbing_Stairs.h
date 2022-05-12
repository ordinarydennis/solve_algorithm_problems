class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {

		int preCost1 = cost[0];
		int preCost2 = cost[1];

		for (int i = 2; i < cost.size(); i++)
		{
			int min = std::min(preCost1, preCost2);
			
			preCost1 = preCost2;
			preCost2 = cost[i] + min;

		}

		int ret1 = preCost2;

		preCost1 = cost[1];
		preCost2 = cost[2];

		for (int i = 3; i < cost.size(); i++)
		{
			int min = std::min(preCost1, preCost2);

			preCost1 = preCost2;
			preCost2 = cost[i] + min;

		}

		preCost2 = std::min(preCost1, preCost2);

		return ret1 < preCost2 ? ret1 : preCost2;

	}
};