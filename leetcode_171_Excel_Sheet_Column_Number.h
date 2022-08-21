class Solution {
public:
	int titleToNumber(string columnTitle) {

		int count = 0;

		int sum = 0;

		for (int i = columnTitle.size() - 1; 0 <= i; i--)
		{
			int num = columnTitle[i] - 'A' + 1;

			for(int a = 0; a < count; a++)
			{
				num *= 26;
			}

			sum += num;
			count++;
		}

		return sum;

	}
};