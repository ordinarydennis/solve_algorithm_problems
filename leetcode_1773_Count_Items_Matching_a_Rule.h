class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

		int keyIndex = 0;

		if ("color" == ruleKey)
		{
			keyIndex = 1;
		}
		else if("name" == ruleKey)
		{
			keyIndex = 2;
		}

		int ret = 0;

		for (const auto& item : items)
		{
			if (item[keyIndex] == ruleValue)
			{
				ret++;
			}
		}

		return ret;
	}
};