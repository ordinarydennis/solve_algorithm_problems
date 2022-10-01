class Solution {
public:
	bool buddyStrings(string s, string goal) {

		if (goal == s)
		{
			return true;
		}

		for (int a = 0; a < s.size() - 1; a++)
		{
			for (int b = a + 1; b < s.size(); b++)
			{
				if (s[a] == s[b])
				{
					continue;
				}

				char t = s[a];
				s[a] = s[b];
				s[b] = t;

				if (s == goal)
				{
					return true;
				}
			}
		}

		return false;

	}
};

