13:30 ~ 14:20

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<int> iList;

		dfs(nums, -1, target, iList);

		return ret;
	}


private:
	void dfs(const vector<int>& nums, int count, int target, vector<int>& iList)
	{
		if (4 <= iList.size())
		{
			int accum = accumulate(iList.begin(), iList.end(), 0);

			if (accum == target)
			{
				ret.push_back(iList);
			}

			return;
		}

		//4 - (nums.size() - count);

		int last = (count + (nums.size() - count)) - 4;

		for (int n = count; n < last; n++)
		{
			iList.push_back(nums[n]);
			dfs(nums, n, target, iList);
			iList.erase(iList.size() - 1, 1);
		}

	}

	vector<vector<int>> ret;

};