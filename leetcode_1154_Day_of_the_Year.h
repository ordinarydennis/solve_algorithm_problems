class Solution {

	bool IsLeapYear(int year)
	{
		bool isLeapYear = false;

		if ((year  % 400) == 0)
		{
			isLeapYear = true;
		}
		else if ((year % 100) != 0 && (year % 4) == 0)
		{
			isLeapYear = true;
		}

		return isLeapYear;
	}


public:
	int dayOfYear(string date) {

		int dayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (IsLeapYear(year))
		{
			dayArr[2]++;
		}

		int ret = 0;

		for (int i = 0; i < month; i++)
		{
			ret += dayArr[i];
		}


		ret += day;

		return ret;
	}
};