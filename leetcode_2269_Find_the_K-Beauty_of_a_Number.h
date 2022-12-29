class Solution {
public:
	int divisorSubstrings(int num, int k) {

		string numStr = to_string(num);

		int ret = 0;

		for (int i = 0; i < numStr.size(); i++)
		{
			string s = numStr.substr(i, k);

			int n = std::stoi(s);

			if (0 == n)
			{
				continue;
			}

			if (0 == num % n)
			{	
				ret++;
			}

			if (numStr.size() - 1 < i + k)
			{
				break;
			}
		}

		return ret;

	}
};