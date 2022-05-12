class Solution {
public:
	bool isSubsequence(string s, string t) {

		int i = 0;

		for (const auto c : t)
			if (s[i] == c)
				i++;

		return s.size() == i;

	}
};