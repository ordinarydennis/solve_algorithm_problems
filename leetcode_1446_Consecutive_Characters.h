class Solution {
public:
	int maxPower(string s) {

		if (1 == s.size())
		{
			return 1;
		}

		char pre = s[0];

		int count = 1;

		int max = INT_MIN;

		for (int i = 1; i < s.size(); i++)
		{
			if (pre == s[i])
			{
				count++;
			}
			else
			{
				max = std::max(max, count);
				count = 1;
				pre = s[i];
			}
		}

		max = std::max(max, count);

		return max;
	}
};

"cc"

//abbcccddddeeeeedcba