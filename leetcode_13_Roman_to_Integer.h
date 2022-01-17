class Solution {
public:
	int romanToInt(string s) {

		map<char, int> m = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}

		};

		int pre = 0;
		int ret = 0;
		for (const auto c : s)
		{
			auto it = m.find(c);

			int cur = it->second;


			if (pre != 0 && pre < cur)
			{
				ret -= pre;

				ret += (cur - pre);
			}
			else
			{
				ret += cur;
			}

			pre = cur;
		}

		return ret;

	}
};