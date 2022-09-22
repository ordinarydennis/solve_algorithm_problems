class Solution {

	string GetOnlyString(const string& licensePlate)
	{
		string ret;

		ret.reserve(licensePlate.size());

		for (const char c : licensePlate)
		{
			if ('a' <= c && c <= 'z')
			{
				ret.push_back(c);
			}
			else if ('A' <= c && c <= 'Z')
			{
				ret.push_back(c);
			}
		}

		return ret;
	}

	bool isUpperCase(char& c)
	{
		return  ('A' <= c && c <= 'Z');
	}


	char UppserToLower(const char& c)
	{
		return 'a' + (c - 'A');
	}

	void ContertAllLowerCase(string& str)
	{
		for (char& c : str)
		{
			if (isUpperCase(c))
			{
				c = UppserToLower(c);
			}
		}
	}

	std::unordered_map<char, int> makeMap(string str)
	{
		std::unordered_map<char, int> m;

		for (const char c : str)
		{
			if (m.count(c))
			{
				m[c]++;
			}
			else
			{
				m[c] = 1;
			}
		}

		return m;
	}

public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {

		string str = GetOnlyString(licensePlate);

		ContertAllLowerCase(str);

		std::unordered_map<char, int> m = makeMap(str);

		std::vector<string> list;

		for (const auto& word : words)
		{
			auto m2 = makeMap(word);

			bool isFind = true;

			for (const auto [c , i] : m)
			{
				auto it = m2.find(c);

				if (m2.end() == it)
				{
					isFind = false;
					break;
				}

				if (it->second != i)
				{
					isFind = false;
					break;;
				}
			}

			if (isFind)
			{
				list.push_back(word);
			}
		}



		int min = INT_MAX;

		string r;
		for (const auto& s : list)
		{
			if (s.size() < min)
			{
				min = s.size();
				r = s;
			}
		}

		return r;
	}
};
