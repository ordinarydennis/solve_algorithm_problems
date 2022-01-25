class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			if (i != 0 && nums[i - 1] == nums[i])
			{
				continue;
			}

			int l = i + 1;
			int r = nums.size() - 1;

			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];

				if (sum == 0)
				{
					ret.push_back(
						std::move(vector<int>{nums[i], nums[l], nums[r]})
					);

					l++;
					r--;

					while (l < r && nums[l] == nums[l - 1]) l++;
					while (l < r && nums[r] == nums[r + 1]) r--;
				}
				else if (0 < sum)
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