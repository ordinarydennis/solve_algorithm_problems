class Solution {

	vector<string> VersionToStringList(string version)
	{
		int i = 0;

		string s;

		vector<string> ret;

		bool zeroLead = true;

		while (true)
		{
			if (version.size() == i)
			{
				break;
			}

			if ('.' == version[i])
			{
				if (s.size())
				{
					ret.push_back(std::move(s));
					zeroLead = true;
				}
			}
			else if ('0' == version[i])
			{
				if (false == zeroLead)
				{
					s += version[i];
				}
			}
			else
			{
				s += version[i];
				zeroLead = false;
			}

			i++;
		}

		return ret;

	}

public:
	int compareVersion(string version1, string version2) {

		auto sList1 = VersionToStringList(version1);
		auto sList2 = VersionToStringList(version2);


		int L = std::max(sList1.size(), sList2.size());

		for (int i = 0; i < L; i++)
		{
			string s1 = "0";
			if (i < sList1.size())
			{
				s1 = sList1[i];
			}
			
			string s2 = "0";
			if (i < sList2.size())
			{
				s2 = sList2[i];
			}

			int c = s1.compare(s2);
			if (0 < c)
			{
				return 1;
			}
			else if (c < 0)
			{
				return -1;
			}
		}

		return 0;

	}
};
