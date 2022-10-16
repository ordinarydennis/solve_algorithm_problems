class Solution {
public:
	string freqAlphabets(string s) {

		string ret;

		for (int i = 0; i < s.size();)
		{
			string numStr;

			if (i + 2 < s.size() && '#' == s[i + 2])
			{
				numStr = s.substr(i, 2);
				i += 3;
			}
			else
			{
				numStr = s.substr(i, 1);
				i += 1;
			}

			if (numStr.size())
			{
				int number = std::atoi(numStr.c_str());
		   
				char c = 'a' + number - 1;

				ret.push_back(c);
			}
		}

		return ret;

	}
};