class Solution {
public:
	int titleToNumber(string columnTitle) {

		int gap = 'Z' - 'A';
		int pos = 0;
		int total = 0;

		for (int i = columnTitle.size() - 1; 0 <= i; i--)
		{
			int num = columnTitle[i] - 'A' + 1;

			total += pos * gap * num + num;

			pos++;
		}

		return total;

	}
};