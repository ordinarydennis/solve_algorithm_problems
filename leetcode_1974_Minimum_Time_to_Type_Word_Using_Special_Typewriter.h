class Solution {
public:
	int minTimeToType(string word) {

		int ret = 0;

		char initc = 'a';

		for (int i = 0; i < word.size(); i++)
		{
			char c = word[i];

			int num = c - initc;
			int num2 = 'z' - c + 1;

			if (num < 0)
			{
				num *= -1;
			}

			if (num < num2)
			{
				ret += num + 1;
			}
			else
			{
				ret += num2 + (initc - 'a') + 1;
			}

			initc = c;
		}

		return ret;
	}
};
