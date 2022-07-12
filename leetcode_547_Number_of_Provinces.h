class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {


		vector<vector<bool>> check(isConnected.size(), 
			vector<bool>(isConnected[0].size(), false)
		);


		int count = 0;

		for (int a = 0; a < isConnected.size(); a++)
		{
			for (int b = 0; b < isConnected[0].size(); b++)
			{

				if (0 == isConnected[a][b])
				{
					continue;
				}


				if (check[a][b] || check[b][a])
				{
					continue;
				}

				if (a == b)
				{
					continue;
				}


				check[a][b] = true;
				check[b][a] = true;

				count++;

			}

		}


		if (isConnected.size() <= count)
		{
			return 1;
		}
		else
		{
			return isConnected.size() - count;
		}
	}
};