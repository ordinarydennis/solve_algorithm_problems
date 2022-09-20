class Solution {
public:
	bool judgeCircle(string moves) {

		int x = 0;
		int y = 0;

		for (const char c : moves)
		{

			if (c == 'U')
			{
				y++;
			}
			else if (c == 'D')
			{
				y--;
			}
			else if (c == 'L')
			{
				x++;
			}
			else
			{
				//R
				x--;
			}

		}


		return (x == 0 && y == 0);

	}
};