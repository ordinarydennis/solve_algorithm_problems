class Solution {
public:
	int maxScore(string s) {

		int max = INT_MIN;

		for (int i = 1; i < s.size(); i++)
		{
			string left = s.substr(0, i);
			string right = s.substr(i, s.size() - i);

			int zeroCount = 0;
			for (int a = 0; a < left.size(); a++)
			{

				if ('0' == left[a])
				{
					zeroCount++;
				}
			}

			int oneCount = 0;
			for (int a = 0; a < right.size(); a++)
			{
				if ('1' == right[a])
				{
					oneCount++;
				}
			}

			max = std::max(max, zeroCount + oneCount);

		}

		return max;

	}
};