class Solution {

public:
	bool backspaceCompare(string s, string t) {

		for (int i = 0; i < static_cast<int>(s.size()); i++)
		{
			if ('#' == s[i])
			{
				if (0 == i)
				{
					s.erase(i, 1);
				}
				else
				{
					s.erase(i - 1, 2);
				}

				i = -1;
			}


		}

		for (int i = 0; i < static_cast<int>(s.size()); i++)
		{
			if ('#' == t[i])
			{
				if (0 == i)
				{
					t.erase(i, 1);
				}
				else
				{
					t.erase(i - 1, 2);

				}

				i = -1;
			}
		}

		return s == t;

	}
};