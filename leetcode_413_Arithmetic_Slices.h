class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {

		if (1 == nums.size())
		{
			return 0;
		}

		int ret = 0;

		int a = 1;

		int diff = nums[a] - nums[a - 1];

		int startIndex = a - 1;
		int length = 0;

		for (int b = a + 1; b < nums.size(); b++)
		{
			if (diff == nums[b] - nums[b - 1])
			{
				if (3 == b - startIndex + 1)
				{
					length = 1;
				}
				else
				{
					length += b - startIndex + 1 - 2;
				}
			}
			else
			{
				startIndex = b - 1;
				ret += length;
				length = 0;
				diff = nums[b] - nums[b - 1];
			}
		}


		//개수 - 2 + 이전
		//3 1 
		//4 3
		//5 6
		//6 10
		//7 15

		ret += length;

		return ret;
	}
};