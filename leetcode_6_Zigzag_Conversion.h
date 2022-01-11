
class Solution {
public:
	string convert(string s, int numRows) {

		if (1 == numRows)
		{
			return s;
		}

		char** table = new char* [numRows];

		for (int i = 0; i < numRows; i++)
		{
			table[i] = new char[s.size()];
			memset(table[i], 0, s.size());
		}

		int row = 0;
		int cul = 0;

		int dir = 1;

		for (const auto c : s)
		{
			table[row][cul] = c;

			row += (dir * 1);

			if (dir < 0)
			{
				cul++;
			}

			if (row == numRows - 1 || row == 0)
			{
				dir *= -1;
			}
		}

		string ret;

		for (int r = 0; r < numRows; r++)
		{
			for (int c = 0; c < s.size(); c++)
			{
				if (0 != table[r][c])
				{
					ret.push_back(table[r][c]);
				}
			}
		}

		for (int i = 0; i < numRows; i++)
		{
			delete[] table[i];
		}

		delete[] table;

		return ret;
	}
};