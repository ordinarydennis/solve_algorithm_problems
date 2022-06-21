class Solution {
public:
	int minDistance(string word1, string word2) {


		int word1Length = word1.size();
		int word2Length = word2.size();

		int minLenght = std::min(word1Length, word2Length);

		int min = INT_MIN;

		for (int a = 0; a < word1Length; a++)
		{
			for (int b = 0; b < word2Length; b++)
			{
				if (word1[a] == word2[b])
				{
					int num = 1;

					for (int c = 1; c < minLenght; c++)
					{

						if (word1Length <= a + c)
						{
							break;
						}

						if (word2Length <= b + c)
						{
							break;
						}


						if (word1[a + c] == word2[b + c])
						{
							num++;
						}
					}

					min = std::max(min, num);
				}

			}
		}

		if (INT_MIN == min)
		{
			return word1Length + word2Length;
		}

		return (word1Length - min) + (word2Length - min);
	}
};