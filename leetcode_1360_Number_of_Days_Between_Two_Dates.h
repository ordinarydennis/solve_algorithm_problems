class Solution {


	bool IsLeepYear(int year)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			return true;
		}

		return false;
	}

public:
	int daysBetweenDates(string date1, string date2) {

		int year_start = std::stoi(date1.substr(0, 4));
		int month_start = std::stoi(date1.substr(5, 2));
		int day_start = std::stoi(date1.substr(8, 2));

		int year_end = std::stoi(date1.substr(0, 4));
		int month_end = std::stoi(date1.substr(5, 2));
		int day_end = std::stoi(date1.substr(8, 2));


		std::vector<int> month = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int ret = 0;

		int start_day = month[month_start] - day_start;

		for (int i = year_start; i <= year_end; i++)
		{
			int m = 1;
			if (year_start == i)
			{
				m += 1;
			}

			int end_month = 12;

			if (i == year_end)
			{
				end_month = month_end - 1;
				break;
			}

			for (; m <= end_month; m++)
			{
				int month_day = month[m];
				if (m == 2 && IsLeepYear(i))
				{
					month_day++;
				}

				start_day = start_day + month_day;
			}

		}


		return start_day;
	}
};
