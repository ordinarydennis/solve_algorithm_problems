// Solution 1
class Solution {

	vector<int> sumList;

	bool dfs(vector<int>& matchsticks, int pos, int sum, int targetSize)
	{
		if (pos == matchsticks.size())
		{
			if (sumList[0] == targetSize &&
				sumList[1] == targetSize &&
				sumList[2] == targetSize)
			{
				return true;
			}

			return false;
		}

		for (int i = 0; i < 4; i++)
		{
			if (targetSize < sumList[i] + matchsticks[pos])
			{
				continue;
			}

			sumList[i] += matchsticks[pos];

			if (dfs(matchsticks, pos + 1, sum + matchsticks[pos], targetSize))
			{
				return true;
			}

			sumList[i] -= matchsticks[pos];

		}

		return false;
	}


public:
	bool makesquare(vector<int>& matchsticks) {

		int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

		if (0 != total % 4)
		{
			return false;
		}

		int targetSize = total / 4;

		sort(matchsticks.begin(), matchsticks.end(), std::greater<>());

		if (targetSize < matchsticks[0])
		{
			return false;
		}


		sumList.resize(4, 0);

		return dfs(matchsticks, 0, 0, targetSize);

	}
};


// Solution 2
class Solution {

public:
	bool makesquare(vector<int>& nums) {
		int n = nums.size();

		long sum = accumulate(nums.begin(), nums.end(), 0l);
		if (sum % 4)
			return false;
		long sideLen = sum / 4;


		vector<int> usedMasks;

		vector<bool> validHalfSubsets(1 << n, false);

		int all = (1 << n) - 1;

		for (int mask = 0; mask <= all; mask++)
		{
			long subsetSum = 0;

			for (int i = 0; i < 32; i++)
			{
				if ((mask >> i) & 1)
					subsetSum += nums[i];
			}

			if (subsetSum == sideLen)
			{
				for (int usedMask : usedMasks)
				{
					if ((usedMask & mask) == 0)
					{
						int validHalf = usedMask | mask;
						validHalfSubsets[validHalf] = true;

						if (validHalfSubsets[all ^ validHalf])
							return true;
					}
				}

				usedMasks.push_back(mask);
			}
		}
		return false;
	}

};
