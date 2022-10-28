class Solution {
public:
	string reformatDate(string date) {

		std::unordered_map<string, string> map = { 
			{"Jan", "1"}, {"Feb", "2"}, {"Mar", "3"}, {"Apr", "4"}, 
			{"May", "5"}, {"Jun", "6"}, {"Jul", "7"}, {"Aug", "8"}, 
			{"Sep","9"}, {"Oct", "10"},{"Nov", "11"},{"Dec", "12"}
		};

		string year = date.substr(date.size() - 4, 4);
		string monthStr = date.substr(date.size() - 8, 3);
		string day;
		if ('0' <= date[1] && date[1] <= '9')
		{
			day = date.substr(0, 2);
		}
		else
		{
			day = "0";
			day += date.substr(0, 1);
		}

		string ret = year;
		ret += "-";

		if (map[monthStr].size() < 2)
		{
			ret += "0" + map[monthStr];
		}
		else
		{
			ret += map[monthStr];
		}
		ret += "-";

		ret += day;

		return ret;

	}
};