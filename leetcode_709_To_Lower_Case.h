class Solution {

	void ConvertToLowerCase(std::string& s)
	{
		for (char& c : s)
		{
			if (isUpperCase(c))
			{
				int g = c - 'A';
				c = 'a' + g;
			}
		}
	}

	bool isUpperCase(char c)
	{
		return ('A' <= c && c <= 'Z');
	}


public:
	string toLowerCase(string s) {

		ConvertToLowerCase(s);

		return s;

	}
};