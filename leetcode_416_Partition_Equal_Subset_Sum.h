class Solution {
private:
	int sum;

public:
	bool canPartition(vector<int>& nums) {

		sum = 0;

		for (int i = 0; i < nums.size(); ++i)
			sum += nums[i];

		if (sum % 2 == 1)
			return false;

		vector<bool>check(sum + 1, false);

		check[0] = true;

		int target = sum / 2;

		for (int i = 0; i < nums.size(); ++i)
		{
			//is element greater than target?
			if (nums[i] > target)
				return false;

			for (int j = target; j >= nums[i]; --j)
			{
				check[j] = check[j] || check[j - nums[i]];

				if (check[j] && j == target)
				{
					return true;
				}
			}
		}
		return check[target];
	}
};