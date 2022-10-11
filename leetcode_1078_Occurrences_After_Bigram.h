class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {

		string word;

		bool isFirst = false;

		vector<string> ret;

		int firstEndIndex = 0;
		for (int i = 0; i <= text.size(); i++)
		{
			if (' ' == text[i] || i == text.size())
			{
				if (false == isFirst)
				{
					if (first == word)
					{
						isFirst = true;
						firstEndIndex = i;
					}
				}
				else
				{
					if (second == word)
					{
						string third;
						for (int a = i + 1; a <= text.size(); a++)
						{
							if (' ' == text[a] || a == text.size())
							{
								ret.push_back(third);
								break;
							}
							third += text[a];
						}
					}

					i = firstEndIndex;
					isFirst = false;
				}

				word = "";
				continue;
			}

			word += text[i];
		}


		return ret;
	}
};

"kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"

["kcyxdfnoa", "kcyxdfnoa"]

"kcyxdfnoa"

"jkypmsxd"

"we we we we will rock you"
"we"
"we"