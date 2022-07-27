class Solution {
public:
	bool equationsPossible(vector<string>& equations) {

		int num = 0;

		std::map<char, int> m;

		for (const auto& s : equations)
		{
			if ('=' == s[1])
			{
				auto it = m.find(s[0]);
				if (m.end() == it)
				{
					auto it2 = m.find(s[3]);
					if (m.end() == it2)
					{
						m[s[0]] = m[s[3]] = num;
						num++;
					}
					else
					{
						m[s[0]] = it2->second;
					}
				}
				else
				{
					auto it2 = m.find(s[3]);

					if (m.end() == it2)
					{
						m[s[3]] = it->second;
					}
					else
					{
						if (it->second != it2->second)
						{
							return false;
						}
					}
					
				}
			}
			else
			{
				auto it = m.find(s[0]);
				if (m.end() == it)
				{
					m[s[0]] = num;
					num++;

					auto it2 = m.find(s[3]);

					if (m.end() == it2)
					{
						m[s[3]] = num;
						num++;
					}
				}
			}
		}


		for (const auto& s : equations)
		{
			if ('=' == s[1])
			{
				if (m[s[0]] != m[s[3]])
				{
					return false;
				}
			}
			else
			{
				if (m[s[0]] == m[s[3]])
				{
					return false;
				}
			}
		}


		return true;

	}
};
