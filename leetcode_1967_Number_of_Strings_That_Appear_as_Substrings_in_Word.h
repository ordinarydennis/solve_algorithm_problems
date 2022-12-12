class Solution {
public:
	int numOfStrings(vector<string>& patterns, string word) {

		int ret = 0;

		for (const auto& s : patterns)
		{
			auto i = word.find(s);

			if (i != string::npos)
			{
				ret++;
			}
		}

		return ret;
	}
};