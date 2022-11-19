class Solution {
public:
	string mergeAlternately(string word1, string word2) {

		string ret;

		int max = std::max(word1.size(), word2.size());

		for (int i = 0; i < max; i++)
		{
			if (i < word1.size())
			{
				ret += word1[i];
			}
		   
			if (i < word2.size())
			{
				ret += word2[i];
			}
			
		}

		return ret;

	}
};