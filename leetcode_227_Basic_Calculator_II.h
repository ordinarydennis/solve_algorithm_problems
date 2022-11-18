class Solution {
public:
	int calculate(string s) {

		std::vector<int> numList;
		std::vector<char> opList;

		int num = 0;

		for (int i = 0 ; i < s.size(); i++)
		{
			char c = s[i];

			if ('+' == c || 
				'-' == c || 
				'*' == c || 
				'/' == c
				)
			{
				opList.push_back(c);

				if ('-' == c)
				{
					num *= -1;
				}
				numList.push_back(num);
				num = 0;
			}
			else
			{
				int num2 = c - '0';
				num = num * 10 + num2;	
			}

		}

		int ret = 0; 

		for (int i = 0; i < opList.size(); i++)
		{
			char o = opList[i];

			if ('*' == o)
			{
				ret += numList[i] * numList[i + 1];
				opList.erase(i, 1);
				numList.erase(i, 2);
				i = -1;
			}
			else if('/' == o)
			{
				ret += numList[i] / numList[i + 1];
				opList.erase(i, 1);
				numList.erase(i, 2);
				i = -1;
			}
		}

		for (int i = 0; i < opList.size(); i++)
		{
			char o = opList[i];

			if ('+' == o)
			{
				ret += numList[i] + numList[i + 1];
				opList.erase(i, 1);
				numList.erase(i, 2);
				i = -1;
			}
			else if ('-' == o)
			{
				ret += numList[i] - numList[i + 1];
				opList.erase(i, 1);
				numList.erase(i, 2);
				i = -1;
			}
		}

		return ret;
	}
};
