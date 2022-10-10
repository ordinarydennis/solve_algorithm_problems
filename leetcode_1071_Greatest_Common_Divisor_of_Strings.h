class Solution {
public:
	string gcdOfStrings(string str1, string str2) {

		string smallStr;		
		string bigStr;		

		if (str1.size() < str2.size())
		{
			smallStr = str1;
			bigStr = str2;
		}
		else
		{
			smallStr = str2;
			bigStr = str1;
		}

		int strSize = smallStr.size();

		int retSize = INT_MAX;

		while (1)
		{
			if (0 != bigStr.size() % strSize)
			{
				strSize--;
				continue;
			}

			string sub = smallStr.substr(0, strSize);

			int i = 0;
			
			for (; i < bigStr.size();)
			{
				if (sub != bigStr.substr(i, strSize))
				{
					break;
				}
				
				i += strSize;
			}

			if (bigStr.size() <= i)
			{
				int a = 0;

				for (; a < smallStr.size();)
				{
					if (sub != smallStr.substr(a, strSize))
					{
						break;
					}

					a += strSize;
				}

				if (smallStr.size() <= a)
				{
					return sub;
				}
			}

			strSize--;

			if (0 == strSize)
			{
				break;
			}
		}

		return "";

	}
};