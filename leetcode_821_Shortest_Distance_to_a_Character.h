class Solution {
public:
	vector<int> shortestToChar(string s, char c) {

		std::vector<int> indexList;

		for (int i = 0; i < s.size(); i++)
		{
			if (c == s[i])
			{
				indexList.push_back(i);
			}
		}

		std::vector<int> ret;

		for (int i = 0; i < s.size(); i++)
		{
			if (c == s[i])
			{
				ret.push_back(0);
			}
			else
			{
				int min = INT_MAX;

				for (const auto ei : indexList)
				{
					int n = std::abs(ei - i);
					if (n < min)
					{
						min = n;
					}
				}

				ret.push_back(min);


			}
		}

		return ret;

	}
};