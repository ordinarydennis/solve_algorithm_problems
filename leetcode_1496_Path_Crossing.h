class Solution {
public:
	bool isPathCrossing(string path) {

		int x = 0;
		int y = 0;

		std::unordered_map<int, std::vector<int>> m;

		m.emplace(x, std::vector<int> { y });

		for (int i = 0; i < path.size(); i++)
		{
			if ('N' == path[i])
			{
				y++;


			}
			else if ('S' == path[i])
			{
				y--;
			}
			else if ('E' == path[i])
			{
				x++;
			}
			else
			{
				//w
				x--;
			}

			auto it = m.find(x);

			if (m.end() == it)
			{
				m.emplace(x, std::vector<int> { y });
			}
			else
			{
				const auto& fIt = std::find(m[x].begin(), m[x].end(), y);

				if (fIt != m[x].end())
				{
					return true;
				}

				m[x].push_back(y);
			}


		}

		return false;
	}
};