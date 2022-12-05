class Solution {
public:
	bool makeEqual(vector<string>& words) {

		int max = INT_MIN;
		int maxIndex = -1;

		int min = INT_MAX;
		int minIndex = -1;

		for (int i = 0; i < words.size(); i++)
		{
			if (max < words[i].size())
			{
				maxIndex = i;
				max = words[i].size();
			}
			if (words[i].size() < min)
			{
				minIndex = i;
				min = words[i].size();
			}
		}

		for (int i = 0; i < words[minIndex].size(); i++)
		{
			int pos = words[maxIndex].find(words[minIndex][i]);

			if (-1 == pos)
			{
				return false;
			}

			words[maxIndex].erase(pos, 1);
		}

		if (words[maxIndex].size() != 2)
		{
			return false;
		}

		return words[maxIndex][0] == words[maxIndex][1];

	}
};