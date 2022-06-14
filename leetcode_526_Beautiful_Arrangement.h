class Solution {
public:
	int countArrangement(int n) {

		int ret = 0;

		for (int i = 0; i < n; i++)
		{
			bool result = true;

			int value = (i + 1) % n;

			int count = 0;

			while (count < n)
			{
				if (0 == i + 1 % value || 0 == value % (i + 1))
				{
					continue;
				}

				result = false;
				break;
			}

			if (result)
			{
				ret++;
			}

			count++;
		}

		return ret;

	}
};