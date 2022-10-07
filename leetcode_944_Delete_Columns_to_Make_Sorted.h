class Solution {
public:
	int minDeletionSize(vector<string>& strs) {

		int sSize = strs[0].size();

		int ret = 0;

		for (int i = 0; i < sSize; i++)
		{
			int preC = strs[0][i];

			for (int a = 1; a < strs.size(); a++)
			{
				if (strs[a][i]  < preC)
				{
					ret++;
					break;
				}
				else
				{
					preC = strs[a][i];
				}

			}
		}

		return ret;
	}
};
