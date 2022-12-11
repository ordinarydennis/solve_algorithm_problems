class Solution {
public:
	bool isPrefixString(string s, vector<string>& words) {

		string ws;

		for (const auto& w : words)
		{
			ws += w;

			if (s.size() == ws.size() && s == ws)
			{
				return true;
			}
		}

		return false;

	}
};