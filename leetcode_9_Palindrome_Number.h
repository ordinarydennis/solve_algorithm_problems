class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
		{
			return false;
		}

		if (0 <= x && x < 10)
		{
			return true;
		}

		vector<char> v;

		while (1)
		{
			v.push_back(static_cast<char>(x % 10));
			x /= 10;

			if (x < 10)
			{
				v.push_back(static_cast<char>(x));
				break;
			}
		}

		int size = v.size();
		int half = static_cast<int>(size / 2);

		for (int l = 0, r = size - 1; l < half; l++, r--)
		{
			if (v[l] != v[r])
			{
				return false;
			}
		}

		return true;

	}
};