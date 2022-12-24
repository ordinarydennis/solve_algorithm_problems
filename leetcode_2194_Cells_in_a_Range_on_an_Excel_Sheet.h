class Solution {
public:
	vector<string> cellsInRange(string s) {

		char startC1 = s[0];
		char startC2 = s[1];

		const auto& last = s.substr(s.size() - 2, 2);
		char lastC1 = last[0];
		char lastC2 = last[1];

		vector<string> ret;

		for (int i = static_cast<int>(startC1); i <= static_cast<int>(lastC1); i++)
		{
			char c = static_cast<char>(i);

			for (int i2 = startC2 - '0'; i2 <= lastC2 - '0'; i2++)
			{
				string s;
				s.push_back(c);
				s += to_string(i2);
				ret.push_back(std::move(s));
			}
		}

		return ret;
	}
};