class Solution {
public:
	bool checkRecord(string s) {

		std::unordered_map<char, int> m;

		char p = ' ';

		int lCount = 0;

		for (char c : s)
		{
			if (p == 'L' && c == 'L')
			{
				lCount++;
			}
			else if(c == 'L')
			{
				lCount = 1;
			}
			else
			{
				lCount = 0;
			}

			if (3 <= lCount)
			{
				return false;
			}

			if (m.count(c))
			{
				m[c]++;
			}
			else
			{
				m[c] = 1;
			}

			p = c;
			
		}

		if (lCount < 3 && m['A'] < 2)
		{
			return true;
		}
		
		return false;
	}
};