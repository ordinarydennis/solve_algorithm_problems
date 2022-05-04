class Solution {


public:
	int nthUglyNumber(int n) {

		int PRIME2 = 1;
		int PRIME3 = 1;
		int PRIME5 = 1;

		int prime2Count = 0;
		int prime3Count = 0;
		int prime5Count = 0;

		int ret = 1;

		for (int i = 1; i < n; i++)
		{

			int num1 = 2 * PRIME2;
			int num2 = 3 * PRIME3;
			int num3 = 5 * PRIME5;

			int minNum = std::min(
				std::min(num1, num2),
				num3
			);

			if (num1 == minNum || 2 == minNum)
			{
				PRIME2 = num1;
				prime2Count++;
			}

			if (num2 == minNum || 3 == minNum)
			{
				PRIME3 = num2;
				prime3Count++;
			}

			if (num3 == minNum || 5 == minNum)
			{
				PRIME5 = num3;
				prime5Count++;
			}

			ret = minNum;
		}


		return ret;

	}
};

class Solution {
public:
	int nthUglyNumber(int n) {
		//for performance
		static vector<int> answer = { 1 };
		static int index2 = 0;
		static int index3 = 0;
		static int index5 = 0;

		while (answer.size() < n) {
			int mul2 = answer[index2] * 2;
			int mul3 = answer[index3] * 3;
			int mul5 = answer[index5] * 5;

			int targetMin = min(mul2, min(mul3, mul5));

			if (targetMin == mul2) index2++;
			if (targetMin == mul3) index3++;
			if (targetMin == mul5) index5++;

			answer.push_back(targetMin);
		}

		return answer[n - 1];
	}
};

