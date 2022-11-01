class Solution {
public:
	string reorderSpaces(string text) {

		if (1 == text.size())
		{
			return text;
		}

		std::vector<string> sList;

		std::string w;
   
		int count = 0;

		for (int i = 0; i < text.size(); i++)
		{
			if (' ' != text[i])
			{
				w += text[i];
			}
			else
			{
				count++;

				if (w.size())
				{
					sList.push_back(w);
					w.clear();
				}
			}
		}

		if (w.size())
		{
			sList.push_back(w);
		}

		string ret;


		if (1 == sList.size())
		{
			ret = sList[0];
			for (int i = 0; i < count; i++)
			{
				ret += " ";
			}
			return ret;
		}

		int sc = count / (sList.size() - 1);
		int scd = count % (sList.size() - 1);

		for (int i = 0; i < sList.size(); i++)
		{
			ret += sList[i];

			if (i == sList.size() - 1)
			{
				break;
			}

			for (int a = 0; a < sc; a++)
			{
				ret += " ";
			}
		}

		for (int i = 0; i < scd; i++)
		{
			ret += " ";
		}

		return ret;
		
	}
};