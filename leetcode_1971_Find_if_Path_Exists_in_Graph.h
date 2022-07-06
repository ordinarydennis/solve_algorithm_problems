class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

		int nextIndex = source;

		for (int a = 0; a < edges.size(); a++)
		{

			if (destination == edges[a][1])
			{
				return true;
			}

			for (int b = a + 1; b < edges.size(); b++)
			{

				if (edges[a][1] == edges[b][0])
				{
					a = b - 1;
				}
			}
		}

		return false;
	}
};