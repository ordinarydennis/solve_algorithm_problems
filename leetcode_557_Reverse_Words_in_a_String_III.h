class Solution {

	void reverse(int s, int e, string& str)
	{
		while (s < e)
		{
			char temp = str[s];
			str[s] = str[e];
			str[e] = temp;
			
			s++;
			e--;
		}
	}

public:
	string reverseWords(string s) {

		int si = 0;
		int ei = 0;

		for (int i = 1; i <= s.size(); i++)
		{
			if (' ' == s[i] || s.size() == i)
			{
				ei = i - 1;
				reverse(si, ei, s);
				si = i + 1;
			}
		}

		return s;
	}
};
