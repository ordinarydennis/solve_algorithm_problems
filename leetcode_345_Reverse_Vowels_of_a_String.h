class Solution {
public:
	string reverseVowels(string s) {

		std::vector<char*> v;

		v.reserve(s.size());

		for (int i = 0; i < s.size(); i++)
		{
			if ('a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i] || 
				'A' == s[i] || 'E' == s[i] || 'I' == s[i] || 'O' == s[i] || 'U' == s[i] )
			{
				v.push_back(&s[i]);
			}
		}

		for (int i = 0; i < v.size() / 2; i++)
		{
			char t = *v[i];
			*v[i] = *v[v.size() - 1 - i];
			*v[v.size() - 1 - i] = t;
		}

		return s;
	}
};