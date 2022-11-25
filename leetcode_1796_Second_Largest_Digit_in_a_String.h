class Solution {
public:
	int secondHighest(string s) {

		std::set<int, std::greater<int>> st;

		for (int i = 0; i < s.size(); i++)
		{
			int n = s[i] - '0';

			if (0 <= n && n < 10)
			{
				st.emplace(n);
			}
		}

		if (1 == st.size() || 0 == st.size())
		{
			return -1;
		}

		auto it = st.begin();

		return *(++it);

	}
};