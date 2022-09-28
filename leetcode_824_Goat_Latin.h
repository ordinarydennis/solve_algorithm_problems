class Solution {

	bool isVowel(char c)
	{
		if ('A' <= c && c <= 'Z')
		{
			c = 'a' + (c - 'A');
		}

		if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c)
		{
			return true;
		}

		return false;

	}

public:
	string toGoatLatin(string sentence) {

		string ret;
		ret.reserve(sentence.size() * 2);

		char startC = sentence[0];

		string w;

		w += startC;

		string aList;

		for (int i = 1; i <= sentence.size(); i++)
		{
			if (' ' == sentence[i] || sentence.size() == i)
			{
				if (false == isVowel(startC))
				{
					w.erase(0, 1);
					w.push_back(startC);
				}

				aList += "a";

				w += "ma" + aList;

				ret += w;

				if (sentence.size() != i)
				{
					ret += " ";
				}

				w.clear();

				startC = ' ';
			}
			else
			{
				if (' ' == startC)
				{
					startC = sentence[i];
				}
				w += sentence[i];
			}
		}

		return ret;
	}
};