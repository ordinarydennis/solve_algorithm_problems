class Solution {
public:
	string reverseWords(string s) {

		string w; 

		vector<string> v;

		string ret;

		for (int i = 0; i <= s.size(); i++)
		{
			if (' ' == s[i] || i == s.size())
			{
				if (w.size())
				{
					v.push_back(std::move(w));
				}				
			}
			else
			{
				w += s[i];
			}
		}

		for (int i = 0; i < v.size() / 2; i++)
		{
			string t = v[i];
			v[i] = v[v.size() - 1 - i];
			v[v.size() - 1 - i] = t;
		}

		for (int i = 0; i < v.size(); i++)
		{
			ret += v[i];

			if (i < v.size() -1)
			{
				ret += ' ';
			}
		}

		return ret;
	}
};
