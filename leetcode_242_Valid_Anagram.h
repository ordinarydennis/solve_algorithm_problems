class Solution {
public:
	bool isAnagram(string s, string t) {

		std::map<char, int> chk1;
		std::map<char, int> chk2;

		for (int i = 0; i < s.size(); i++)
		{
			if (chk1.count(s[i]))
			{
				chk1[s[i]]++;
			}
			else
			{
				chk1.emplace(s[i], 1);
			}
		}

		for (int i = 0; i < t.size(); i++)
		{
			if (chk2.count(t[i]))
			{
				chk2[t[i]]++;
			}
			else
			{
				chk2.emplace(t[i], 1);
			}
		}

		return chk1.size() == chk2.size() && 
			std::equal(
				chk1.begin(), chk1.end(), 
				chk2.begin()
			);
	}
};