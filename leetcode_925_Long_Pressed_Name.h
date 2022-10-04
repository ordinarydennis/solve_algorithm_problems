class Solution {
public:
	bool isLongPressedName(string name, string typed) {

		int a = 0;

		for (int i = 0; i < name.size(); i++)
		{
			if (typed[a] != name[i])
			{
				char pre = typed[a];
				bool isFind = false;
				while (a < typed.size())
				{
					a++;
					if (name[i] == typed[a])
					{
						isFind = true;
						break;
					}
					else if(pre != typed[a])
					{
						break;
					}
				}

				if (false == isFind)
				{
					return false;
				}
			}

			a++;

		}

		char last = name[name.size() - 1];

		for (int i = a; i < typed.size(); i++)
		{
			if (last != typed[i])
			{
				return false;
			}
		}

		return true;

	}
};


"x"
"elx"