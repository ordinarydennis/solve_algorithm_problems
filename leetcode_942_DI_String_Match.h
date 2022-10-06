class Solution {
public:
	vector<int> diStringMatch(string s) {

		int dCount = s.size();
		int iCount = 0;

		vector<int> ret;
		ret.reserve(s.size() + 1);

		for (int i = 0; i <= s.size(); i++)
		{
			if ('I' == s[s.size() == i ? i - 1 : i])
			{
				ret.push_back(iCount++);
			}
			else
			{
				ret.push_back(dCount--);
			}
		}

		return ret;

	}
};