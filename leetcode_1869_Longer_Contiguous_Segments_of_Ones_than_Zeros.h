class Solution {
public:
	bool checkZeroOnes(string s) {

		int one = 0;
		int oneMax = 0;
		int zero = 0;
		int zeroMax = 0;

		for (int i =  0; i < s.size(); i++)
		{
			if ('1' == s[i])
			{
				one++;
				zeroMax = std::max(zeroMax, zero);
				zero = 0;
			}
			else
			{
				zero++;
				oneMax = std::max(oneMax, one);
				one = 0;
			}
		}

		zeroMax = std::max(zeroMax, zero);
		oneMax = std::max(oneMax, one);

		return zeroMax < oneMax;

	}
};