class Solution {
public:
	string interpret(string command) {

		bool isOpen = false;

		string s;

		string ret;

		for (int i = 0; i < command.size(); i++)
		{
			if ('(' == command[i])
			{
				isOpen = true;
				continue;
			}
			else if (')' == command[i])
			{
				isOpen = false;

				if (s.size())
				{
					ret += s;
					s.clear();
				}
				else
				{
					ret += 'o';
				}
			}
			else
			{
				if (isOpen)
				{
					s += command[i];
				}
				else
				{
					ret += command[i];;
				}			
			}
		}


		return ret;

	}
};

// "G()()()()(al)"