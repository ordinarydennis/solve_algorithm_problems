class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {

		//좌표가 정렬이 안되어 있다면 정렬하자
		int ret = 0;

		vector<vector<int>> plane(1000, vector<int>(1000, 0));

		int maxColumn = 1000;
		int maxRow = 1000;

		for (const auto& stonePoint : stones)
		{
			plane[stonePoint[1]][stonePoint[0]] = 1;
		}

		for (int i = stones.size() - 1; 0 <= i; i--)
		{
			bool found = false;

			const auto& stonePoint = stones[i];

			int x = stonePoint[0];

			for (int i = 0; i < maxRow; i++)
			{
				if (plane[i][x])
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				ret++;
				continue;
			}

			int y = stonePoint[1];

			for (int i = 0; i < maxColumn; i++)
			{
				if (plane[y][i])
				{

					found = true;
					break;
				}
			}

			if (found)
			{
				ret++;
				continue;
			}
		}

		return ret;

	}
};