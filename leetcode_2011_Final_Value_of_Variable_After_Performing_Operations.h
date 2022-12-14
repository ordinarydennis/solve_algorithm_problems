class Solution {
public:
	int finalValueAfterOperations(vector<string>& operations) {

		int ret = 0;

		for (const auto& s : operations)
		{
			if ("X++" == s || "++X" == s)
			{
				ret++;
			}
			else
			{
				ret--;
			}
		}

		return ret++;
	}
};