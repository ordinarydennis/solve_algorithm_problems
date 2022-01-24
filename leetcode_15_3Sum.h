class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		int numSize = nums.size();

		vector<vector<int>> ret;

		for (int i = 0; i < numSize; i++)
		{
			int l = 0;
			int r = numSize - 1;

			while (l < r)
			{
				if (i == l)
				{
					l++;
					continue;
				}

				if (i == r)
				{
					r--;
					continue;
				}

				int sum = nums[l] + nums[r];

				if (sum + nums[i] == 0)
				{
					vector<int> v = { nums[i], nums[l], nums[r] };
					sort(v.begin(), v.end());
					auto it = find(ret.begin(), ret.end(), v);
					if (it == ret.end())
					{
						ret.push_back(v);
						break;
					}
				}

				if ((-1 * nums[i]) < sum)
				{
					r--;
				}
				else
				{
					l++;
				}
			}
		}

		return ret;

	}

};