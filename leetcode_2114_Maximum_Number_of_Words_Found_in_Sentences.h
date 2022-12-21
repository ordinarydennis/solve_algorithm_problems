class Solution {
public:
	int mostWordsFound(vector<string>& sentences) {

		int ret = INT_MIN;

		for (int i = 0; i < sentences.size(); i++)
		{
			const auto& s = sentences[i];

			int max = 0;

			for (const char c : s)
			{
				if (' ' == c)
				{
					max++;
				}
			}

			ret = std::max(max, ret);
		}

		return ret + 1;
	}
};