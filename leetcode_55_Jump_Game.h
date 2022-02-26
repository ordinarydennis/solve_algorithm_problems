//[2,3,1,1,4] 일 때, m 의 변화 --> 0 2 4 4 4
class Solution {
public:
	bool canJump(vector<int>& nums) {

		if (nums.size() == 1)
		{
			return true;
		}

		int m = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (m < i)
			{
				return false;
			}

			m = max(m, i + nums[i]);

			if (nums.size() - 1 <= m)
			{
				return true;
			}
		}

		return false;
	}
};