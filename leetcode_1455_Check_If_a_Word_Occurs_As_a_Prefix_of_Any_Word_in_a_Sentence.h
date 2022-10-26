class Solution {

	bool isPrefix(const string& word, const string& searchWord)
	{
		if (word.size() < searchWord.size())
		{
			return false;
		}

		for (int i = 0; i < searchWord.size(); i++)
		{
			if (searchWord[i] != word[i])
			{
				return false;
			}
		}

		return true;
	}
public:
	int isPrefixOfWord(string sentence, string searchWord) {

		string w;
		int count = 0;

		for (int i = 0; i <= sentence.size(); i++)
		{
			if(' ' == sentence[i] || i == sentence.size())
			{
				count++;
				if (isPrefix(w, searchWord))
				{
					return count;
				}
				
				w.clear();
			}
			else
			{
				w += sentence[i];
			}
			
		}

		return -1;

	}
};