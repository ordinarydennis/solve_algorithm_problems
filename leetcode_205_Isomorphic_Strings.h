class Solution {
public:
	bool isIsomorphic(string s, string t) {

		std::map<char, char> chk;

		for (int i = 0; i < s.size(); i++)
		{
			const auto& it = chk.find(s[i]);
			
			if (chk.end() == it)
			{
				char tc = t[i];

				const auto& f = std::find_if(
					chk.begin(), 
					chk.end(), 
					[&tc](const auto& c) { return tc == c.second; }
				);

				if (chk.end() != f)
				{
					return false;
				}

				chk.emplace(s[i], t[i]);
			}
			else
			{
				if (it->second != t[i])
				{
					return false;
				}	
			}

		}

		return true;
	}
};