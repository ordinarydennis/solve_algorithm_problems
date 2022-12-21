class Solution {
public:
	bool checkString(string s) {

		bool sb = false;

		for (const char c : s)
		{
			if (!sb && 'b' == c)
			{
				sb = true;
				continue;
			}

			if (sb && 'a'  == c)
			{
				return false;
			}
		}

		return true;

	}
};