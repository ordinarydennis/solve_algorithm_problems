class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {

		if (s1 == s2)
		{
			return true;
		}

		for (int a = 0; a < s1.size() - 1; a++)
		{
			for (int b = a + 1; b < s1.size(); b++)
			{
				std::swap(s1[a], s1[b]);

				if (s1 == s2)
				{
					return true;
				}

				std::swap(s1[b], s1[a]);
			}
		}

		return false;

	}
};