//"leet"
//"delete"
det lee
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {


		vector<int> cList;

		if (s2.size() < s1.size())
		{
			string temp = s1;
			s1 = s2;
			s2 = temp;
		}

		int lastB = 0;

		for (int a = 0; a < s1.size(); a++)
		{
			bool found = false;

			for (int b = lastB; b < s2.size(); b++)
			{
				if (s1[a] == s2[b])
				{
					lastB = b + 1;
					found = true;
					break;
				}
				else
				{
					cList.push_back(static_cast<int>(s2[b]));
				}
			}

			if (false == found)
			{
				cList.push_back(static_cast<int>(s1[a]));
			}
		}

		return std::accumulate(cList.begin(), cList.end(), 0);

	}
};