class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {

		if (s.size() <= 10)
		{
			return {};
		}

		set<string> sSet;

		for (int a = 0; a <= s.size() - 10; a++)
		{
			string str = s.substr(a, 10);

			for (int b = a + 1; b <= s.size() - 10; b++)
			{
				if (str == s.substr(b, 10))
				{
					sSet.emplace(str);
					break;
				}
			}
		}

		std::vector<string> ret;
		ret.reserve(sSet.size());

		for (auto& s : sSet)
		{
			ret.push_back(std::move(s));
		}

		return ret;

	}
};