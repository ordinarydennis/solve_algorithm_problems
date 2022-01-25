class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			int pivot = nums[i];
			int l = i + 1;
			int r = nums.size() - 1;
			int target = pivot * -1;

			while (l < r)
			{
				int sum = nums[l] + nums[r];

				if (sum == target)
				{
					ret.push_back(vector<int>{target, nums[l] , nums[r]});
					l++;
					r--;

					while (l < r)
					{
						if (nums[l] == nums[l - 1]) l++;
						if (nums[r] == nums[r - 1]) r--;
					}
				}
				else if (target < sum)
				{
					r--;
				}
				else
				{
					l--;
				}



			}




		}







		return ret;

	}

};