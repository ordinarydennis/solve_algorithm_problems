class Solution {
public:
	string removeDigit(string number, char digit) {

		vector<string> sv;

		int fCount = 0;
		int fCount2 = 0;

		string ori = number;

		for (int i = 0 ; i < number.size(); i++)
		{
			if (digit == number[i])
			{
				if (fCount2 < fCount)
				{
					fCount2++;
					continue;
				}

				sv.push_back(number.erase(i, 1));
				number = ori;
				i = -1;
				fCount++;
				fCount2 = 0;
			}
		}

		string m;
		for (const auto& s : sv)
		{
			if (m < s)
			{
				m = s;
			}
		}

		return m;
	}
};