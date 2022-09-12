class Solution {
public:
	bool repeatedSubstringPattern(string s) {

		string sub;

		for (int i = 1; i < s.size(); i++)
		{
			string sub = s.substr(0, i);

			for (int a = sub.size(); a < s.size();)
			{
				if (s.size() < a + sub.size())
				{
					break;
				}

				string sub2 = s.substr(a, sub.size());

				if (sub != sub2)
				{
					break;
				}
				else
				{
					if (s.size() == a + sub.size())
					{
						return true;
					}
				}

				a += sub.size();
			}
		}

		return false;
	}
};