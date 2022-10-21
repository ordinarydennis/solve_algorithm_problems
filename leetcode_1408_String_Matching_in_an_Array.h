class Solution {
public:
	vector<string> stringMatching(vector<string>& words) {

		int size = words.size();

		vector<string> ret;

		for (int a = 0; a < size - 1; a++)
		{
			for (int b = a + 1; b < size; b++)
			{
				if (words[a].size() < words[b].size())
				{

					auto it = words[b].find(words[a]);
					if (it != std::string::npos)
					{
						if (ret.end() == std::find(ret.begin(), ret.end(), words[a]))
						{
							ret.push_back(words[a]);
						}
					}
				}
				else
				{
					auto it = words[a].find(words[b]);
					if (it != std::string::npos)
					{
						if (ret.end() == std::find(ret.begin(), ret.end(), words[b]))
						{
							ret.push_back(words[b]);
						}
					}
				}
			}
		}

		return ret;

	}
};



["leetcoder", "leetcode", "od", "hamlet", "am"]

["leetcode", "od", "od", "am"]