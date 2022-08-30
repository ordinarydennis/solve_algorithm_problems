class Solution {
public:
	int lengthOfLastWord(string s) {

		int count = 0;

		for(int i = s.size() - 1; 0 <= i; i--)
		{
			if (' ' == s[i])
			{
				if (0 < count)
				{
					break;
				}

				continue;
			}

			count++;
		}

		return count;

	}
};