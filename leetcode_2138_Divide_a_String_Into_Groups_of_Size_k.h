class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {

		vector<string> ret;

		for (int i = 0; i < s.size();)
		{
			ret.push_back(s.substr(i, k));

			i += k;
		}

		auto& last = ret[ret.size() - 1];

		while (last.size() < k)
		{
			last += fill;
		}

		return ret;
	}
};