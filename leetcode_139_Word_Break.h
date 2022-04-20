class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		vector<string> wordDict2;

		for (const auto& word : wordDict)
		{
			auto pos = s.find(word);

			if (std::string::npos == pos)
			{
				bool isFind = false;

				for (const auto& word2 : wordDict2)
				{
					if (std::string::npos != word2.find(word))
					{
						isFind = true;
						break;
					}
				}

				if (false == isFind)
				{
					return false;
				}
			}

			auto str = s.substr(pos, word.size());

			s.erase(pos, word.size());

			if (0 == s.size())
			{
				return true;
			}

			wordDict2.push_back(str);
		}


		return true;
	}
};