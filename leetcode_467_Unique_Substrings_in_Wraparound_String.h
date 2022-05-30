class Solution {

public:
	int findSubstringInWraproundString(string p) {

		vector<string> list;

		for (int i = 0; i < p.size(); i++)
		{
			
			string ss; 

			ss += p[i];

			list.push_back(ss);

			for (int a = i + 1; a < p.size(); a++)
			{
				ss = ss + p[a];
				list.push_back(ss);
			}
		}

		return list.size();

	}
};
