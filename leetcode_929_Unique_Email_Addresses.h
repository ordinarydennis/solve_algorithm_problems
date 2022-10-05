class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {

		std::unordered_map<string, int> m;

		for (const string& e : emails)
		{

			string es;
			bool isIgnore = false;
			for (int i = 0; i < e.size(); i++)
			{
				char c = e[i];
				if ('@' == c)
				{
					es += e.substr(i, e.size() - i);
					break;
				}

				if (isIgnore || '.' == c)
				{
					continue;
				}

				if ('+' == c)
				{
					isIgnore = true;
					continue;
				}

				es += e[i];
			}

			if (m.count(es))
			{
				m[es]++;
			}
			else
			{
				m.emplace(es, 1);
			}
		}

		return m.size();

	}
};
