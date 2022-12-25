class Solution {

	int timeToM(const string s)
	{
		char c1 = s[0];
		char c2 = s[1];

		int n1 = c1 - '0';
		int n2 = c2 - '0';

		int h = (n1 * 10) + n2;

		c1 = s[s.size() - 2];
		c2 = s[s.size() - 1];

		n1 = c1 - '0';
		n2 = c2 - '0';

		int m = (n1 * 10) + n2;

		return h * 60 + m;
	}


public:
	int convertTime(string current, string correct) {

		int currentM = timeToM(current);
		int correctM = timeToM(correct);

		int rm = correctM - currentM;

		int ret = 0;

		while (rm)
		{
			if (rm / 60)
			{
				ret += rm / 60;
				rm  %= 60;
			}
			else if (rm / 15)
			{
				ret += rm / 15;
				rm %= 15;
			}
			else if (rm / 5)
			{
				ret += rm / 5;
				rm %= 5;
			}
			else if(rm / 1)
			{
				ret += rm / 1;
				rm %= 1;
			}
		}
		
		return ret;
	}
};