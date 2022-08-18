
class Solution {
public:
	int majorityElement(vector<int>& nums) {

		std::unordered_map<int, int> countMap;

		int max = INT_MIN;

		int ret = nums[0];

		for (int n : nums)
		{
			if (countMap.count(n))
			{
				countMap[n]++;

				if (max < countMap[n])
				{
					ret = n;
					max = countMap[n];
				}
			}
			else
			{
				countMap.emplace(n, 1);
			}
		}

		return ret;

	}
};