class Solution {
public:
    vector<string> letterCombinations(string digits) {

		map<char, int> m = {
			{'2', "abc"},
			{'3', "edf"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};
	
		map<string, int> sMap;

		for(const auto c : digits)
		{
			auto it = m.find(c);
			if(it == m.end())
			{
				continue;
			}

			sMap.emplace(it->second, 0);
		}


		vector<string> ret;

		int mapS = sMap.size();

		while(1)
		{
			int loopIndex = 0;

			string loopStr;

			for(auto& [str, index]: sMap)
			{
				loopIndex++;

				loopStr.push_back(str[index]);

				if(mapS == loopIndex)
				{
					index++;

					if(index == str.size())
					{
						index = 0;
						mapS--;
					}
				}

				
	
			}

			ret.push_back(loopStr);
		}

		return ret;
    }
};