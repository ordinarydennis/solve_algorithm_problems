class Solution {
public:
	int countValidWords(string sentence) {

		string w;

		int ret = 0;

		for (int i = 0; i <= sentence.size(); i++)
		{
			if (sentence.size() == i || ' ' == sentence[i] && w.size())
			{
				bool isValid = true;
				int count = 0; 
				for (int a = 0; a < w.size(); a++)
				{
					if ('0' <= w[a] && w[a] <= '9')
					{
						isValid = false;
						break;
					}

					if ('-' == w[a])
					{
						count++;

						if (1 < count)
						{
							isValid = false;
							break;
						}
						if (0 == a || w.size() - 1 == a)
						{
							isValid = false;
							break;
						}

						if (w[a - 1] < 'a' || 'z' < w[a - 1])
						{
							isValid = false;
							break;
						}

						if (w[a + 1] < 'a' || 'z' < w[a + 1])
						{
							isValid = false;
							break;
						}
					}

					if ('!' == w[a] || '.' == w[a] || ',' == w[a])
					{
						if (a != w.size() - 1)
						{
							isValid = false;
							break;
						}
					}
				}

				if (isValid)
				{
					ret++;
				}

				w.clear();
			}
			else
			{
				if (' ' != sentence[i])
				{
					w += sentence[i];
				}
			}
		}

		return ret;

	}
};