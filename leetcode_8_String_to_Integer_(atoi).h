//18:40 - 19:30
class Solution {
public:
	int myAtoi(string s) {

		double ret = 0;

		bool isM = false;

		int numbase = static_cast<int>('0');

		bool zeroCheck = false;

		bool isStart = false;

		for (const auto c : s)
		{
			if (' ' == c)
			{
				if (isStart)
				{
					break;
				}
				else
				{
					continue;
				}
			}

			if ('-' == c)
			{
				if (isStart)
				{
					break;
				}
				if (zeroCheck)
				{
					break;
				}
				isM = true;
				isStart = true;
				continue;
			}

			if ('+' == c)
			{
				if (isStart)
				{
					break;
				}
				isStart = true;
				continue;
			}

			int n = static_cast<int>(c);

			int reNum = n - numbase;

			if (0 == reNum && false == isStart)
			{
				zeroCheck = true;
				continue;
			}

			if (reNum < 0 || 10 < reNum)
			{
				break;
			}

			ret = ret * 10 + reNum;
			
			if (INT_MAX <= ret)
			{
				if (isM)
				{
					if (INT_MAX < ret)
					{
						ret = INT_MAX;
					}
				}
				else
				{
					ret = INT_MAX;
				}
				
				break;
			}

			isStart = true;

		}

		if (isM)
		{
			if (INT_MAX < ret)
			{
				ret = INT_MIN;
			}
			else
			{
				ret *= -1;
			}
		}

		return static_cast<int>(ret);
	}
};