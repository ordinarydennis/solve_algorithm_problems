class Solution {
public:
	string generateTheString(int n) {

		std::string ret;

		ret.reserve(n);

		int AlpabetCount  = 'z' - 'a' + 1;

		int end = std::min(AlpabetCount, n);
		
		for (int i = 0; i < end; i++)
		{
			ret += 'a' + i;
		}

		if (AlpabetCount < n)
		{
			for (int i = 0; i < 10; i++)
			{
				ret += 'a' + i;
			}
		}

		return ret;
	
	}
};