class Solution {
public:
	int minOperations(vector<string>& logs) {

		int ret = 0;

		for (const string& s : logs)
		{

			if ("../" == s)
			{
				ret = std::max(0, ret - 1);
			}
			else if ("./" == s)
			{

			}
			else
			{
				ret++;
			}
		}

		return ret;

	}
};