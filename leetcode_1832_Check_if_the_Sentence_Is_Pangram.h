class Solution {
public:
	bool checkIfPangram(string sentence) {

		std::unordered_set<char> s;

		int maxCount = 'z' - 'a' + 1;

		for (char c : sentence)
		{
			s.emplace(c);
		}

		return maxCount == s.size();

	}
};
