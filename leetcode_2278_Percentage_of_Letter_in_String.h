class Solution {
public:
	int percentageLetter(string s, char letter) {

		int count = 0;

		for (const char c : s)
		{
			if (letter == c)
			{
				count++;
			}
		}
		
		return (count * 100) / s.size();
	}
};