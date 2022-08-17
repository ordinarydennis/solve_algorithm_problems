class Solution {
public:
	int edgeScore(vector<int>& edges) {

		std::map<int, unsigned int> edgeScoreMap;

		for (int i = 0; i < edges.size(); i++)
		{
			int nodeIndex = edges[i];

			if (edgeScoreMap.count(nodeIndex))
			{
				edgeScoreMap[nodeIndex] += i;
			}
			else
			{
				edgeScoreMap.emplace(nodeIndex, i);
			}
		}

		unsigned int max = 0;

		int retIndex = 0;

		for (const auto& [index, score] : edgeScoreMap)
		{
			if (max <= score)
			{
				if (max == score)
				{
					retIndex = std::min(retIndex, index);
				}
				else
				{
					retIndex = index;
				}

				max = score;

			}
		}

		return retIndex;

	}
};