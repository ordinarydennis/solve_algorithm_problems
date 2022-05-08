class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {

		std::vector<int> clist(primes.size(), 0);

		std::vector<int> dp(1, 1);


		while (dp.size() < n)
		{
			std::vector<int> mList;

			for (int i = 0; i < clist.size(); i++)
			{
				mList.push_back(dp[clist[i]] * primes[i]);
			}

			int eMin = *min_element(
				mList.begin(),
				mList.end()
			);

			dp.push_back(eMin);

			for (int i = 0; i < clist.size(); i++)
			{
				if (eMin == dp[clist[i]] * primes[i])
				{
					clist[i]++;
				}
			}
		}

		return dp.back();
	}
};