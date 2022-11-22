class Solution {
public:
	string getHint(string secret, string guess) {

		std::unordered_map<int, std::vector<int>> mv;

		for (int i = 0; i < secret.size(); i++)
		{
			auto it = mv.find(secret[i]);

			if (mv.end() == it)
			{
				mv.emplace(secret[i], vector<int> {i});
			}
			else
			{
				it->second.push_back(i);
			}
		}

		int countA = 0;
		int countB = 0;

		for (int i = 0; i < guess.size(); i++)
		{

			auto it = mv.find(guess[i]);
			if (mv.end() == it)
			{
				continue;
			}

			auto fi = std::find(it->second.begin(), it->second.end(), i);

			if (it->second.end() != fi)
			{
				countA++;
				it->second.erase(fi);
			}
			else
			{
				mv.find(guess[i]);
				it->second.erase(it->second.begin());
				countB++;
			}

			if (0 == it->second.size())
			{
				mv.erase(guess[i]);
			}
		}

		string ret = std::to_string(countA) + "A" + std::to_string(countB) + "B";

		return ret;
	}
};