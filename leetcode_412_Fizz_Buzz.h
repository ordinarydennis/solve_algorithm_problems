class Solution {
public:
	vector<string> fizzBuzz(int n) {

		vector<string> ret;

		ret.reserve(n);

		for (int i = 1; i <= n; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				ret.push_back("FizzBuzz");
			}
			else if (i % 3 == 0)
			{
				ret.push_back("Fizz");
			}
			else if (i % 5 == 0)
			{
				ret.push_back("Buzz");
			}
			else
			{
				ret.push_back(std::to_string(i));
			}
		}

		return ret;

	}
};