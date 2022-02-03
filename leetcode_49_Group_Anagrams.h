class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		vector<vector<string>> ret;

		for (auto a = strs.begin(); a != strs.end();)
		{
			vector<string> ana;

			for (auto b = a + 1; b != strs.end();)
			{
				string aStr = *a;
				string bStr = *b;

				sort(aStr.begin(), aStr.end());
				sort(bStr.begin(), bStr.end());

				if (aStr == bStr)
				{
					ana.push_back(*b);
					b = strs.erase(b);
				}
				else
				{
					++b;
				}	
			}

			ana.push_back(*a);
			ret.push_back(ana);
			a = strs.erase(a);
			
		}

		return ret;
	}
};