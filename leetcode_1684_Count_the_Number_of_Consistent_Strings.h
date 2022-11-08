class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {

		int count = 0;

		for (const string& w : words)
		{
			bool isFind = true;

			for (const char c : w)
			{
				const auto& it = std::find(allowed.begin(), allowed.end(), c);

				if (it == allowed.end())
				{
					isFind = false;
					break;
				}
			}

			if (isFind)
			{
				count++;
			}
		}

		return count;

	}
};