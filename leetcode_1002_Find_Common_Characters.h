class Solution {
public:
	vector<string> commonChars(vector<string>& words) {

		std::vector<int, std::map<char, int>> mm;

		mm.reserve(words.size());

		for (int i = 0; i < words.size(); i++)
		{
			std::map m;

			for (int a = 0; a < words[i].size(); a++)
			{
				char c = words[i][a];

				if (m.count(c))
				{
					m[c] = 1;
				}
				else
				{
					m[c]++;
				}
			}

			mm.emplace(i, std::move(m));
		}


		while (1)
		{
			int step = 0;

			for (int i = 0; i < words.size(); i++)
			{
				if (words[i].size() <= step)
				{

				}

				words[i][step];

			}
		}
	}
};