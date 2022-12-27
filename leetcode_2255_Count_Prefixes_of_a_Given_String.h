class Solution {
public:
	int countPrefixes(vector<string>& words, string s) {

		int ret = 0;

		for (const auto& str : words)
		{
			const string sub = s.substr(0, str.size());
			if (sub == str)
			{
				ret++;
			}
		}

		return ret;
	}
};