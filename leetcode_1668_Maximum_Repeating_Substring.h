class Solution {
public:
	int maxRepeating(string sequence, string word) {

		char fc = word[0];

		int count = 0;

		for (int i = 0 ;i < sequence.size(); )
		{
			if (fc != sequence[i])
			{
				i++;
				continue;
			}

			auto sub = sequence.substr(i, word.size());

			if (word == sub)
			{
				count++;
				i += word.size();
			}
			else
			{
				i++;
			}
		}

		return count;

	}
};