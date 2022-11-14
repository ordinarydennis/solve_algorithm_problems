class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {

		float result = float(numerator) / float(denominator);

		std::string ret = std::to_string(result);

		bool f = false;

		for (int i = 0 ; i < ret.size(); i++)
		{
			if ('.' == ret[i])
			{
				f = true;
				continue;
			}

			if (f)
			{
				if ('0' == ret[i])
				{
					if ('.' == ret[i - 1])
					{
						ret.erase(i-1);
					}
					else
					{
						ret.erase(i);
					}
					
					break;
				}
			}
		}

		return ret;

	}
};