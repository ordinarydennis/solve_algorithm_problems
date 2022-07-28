class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
	
	if (trust.empty())
	{
		if (n == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}

	}

	std::unordered_map<int, std::vector<int>> trustAB;
	std::unordered_map<int, std::vector<int>> trustBA;


	for (const auto& trustAssociate : trust)
	{
		trustAB[trustAssociate[0]].push_back(trustAssociate[1]);
		trustBA[trustAssociate[1]].push_back(trustAssociate[0]);
	}

	for (const auto& [b, trustList] : trustBA)
	{
		if (trustList.size() == n - 1)
		{
			if (trustAB[b].size() == 0)
			{
				return b;
			}
		}
	}

	return -1;

	}
};