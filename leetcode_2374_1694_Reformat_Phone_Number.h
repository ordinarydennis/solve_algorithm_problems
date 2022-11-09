class Solution {
public:
	string reformatNumber(string number) {

		string reStr;

		reStr.reserve(number.size());

		for (const char c : number)
		{
			if (' ' == c || '-' == c)
			{
				continue;
			}

			reStr += c;
		}

		string ret;

		for (int i = 0; i < reStr.size();)
		{
			int remainSize = reStr.size() - i;

			if (4 < remainSize)
			{
				//3
				ret += reStr.substr(i, 3);
				ret += '-';
				i += 3;
			}
			else if (4 == remainSize)
			{
				//2 2
				ret += reStr.substr(i, 2);
				ret += '-';
				i += 2;
				ret += reStr.substr(i, 2);
				break;
			}
			else
			{
				//all
				ret += reStr.substr(i);
				break;
			}
		}

		return ret;
	}
};