class Solution {

	int getStrToNum(const string& strNum)
	{
		int realNum = 0;

		for (int i = 0; i < strNum.size(); i++)
		{
			int index = strNum.size() - i - 1;

			int num = strNum[index] - '0';

			int m = 1;

			for (int a = 0; a < i; a++)
			{
				m *= 10;
			}

			realNum += (num * m);
		}

		return realNum;
	}


public:
	string multiply(string num1, string num2) {

		int realNum1 = getStrToNum(num1);
		int realNum2 = getStrToNum(num2);

		int mul = realNum1 * realNum2;

		string ret;

		do
		{
			int num = mul % 10;

			ret += '0' + num;

			mul /= 10;

		} while (mul);

		std::reverse(ret.begin(), ret.end());

		return ret;

	}
};