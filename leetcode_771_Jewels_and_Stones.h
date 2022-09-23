class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {

		std::unordered_set<char> cetc;

		for (const char c : jewels)
		{
			cetc.insert(c);
		}

		int ret = 0;
		for (const char c : stones)
		{
			if (cetc.count(c))
			{
				ret++;
			}
		}

		return ret;
	}
};