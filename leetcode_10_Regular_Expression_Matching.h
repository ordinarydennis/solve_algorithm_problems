class Solution {
public:
	bool isMatch(string s, string p) {

		bool result = false;
		bool optionA = false;
		//bool optionD = false;

		//패턴 분석
		if (p.find(".") != string::npos)
		{
			return !s.empty();
		}


		if (p.find("*") != string::npos)
		{
			optionA = true;
		}

		//if (s.find(".") != string::npos)
		//{
		//	//optionD = true;
		//}

		vector<string> pSList;

		string pS;

		for (const auto c : p)
		{
			if (c == '*')
			{
				if (false == pS.empty())
				{
					pSList.push_back(pS);
					pS.clear();
				}

				continue;
			}

			if (c == '.')
			{
				continue;
			}

			pS.push_back(c);
		}

		if (false == pS.empty())
		{
			pSList.push_back(pS);
		}


		if (optionA)
		{
			for (const auto& str : pSList)
			{
				if (s.find(str) != string::npos)
				{
					return true;
				}
			}
		}

		return result;
	}

};