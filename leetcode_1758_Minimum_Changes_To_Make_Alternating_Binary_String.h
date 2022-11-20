class Solution {
public:
	int minOperations(string s) {

		int num0 = 0;
		int num1 = 1;

		int count0 = 0;
		int count1 = 0;

		for (char c : s)
		{
			int n = c - '0';

			//if it starts with zero
			if (num0 == n)
			{
				count0++;
			}

			//if it starts with one
			if (num1 == n)
			{
				count1++;
			}

			std::swap(num0, num1);
		}

		return std::min(count0, count1);

	}
};

