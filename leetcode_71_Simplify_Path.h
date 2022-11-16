class Solution {
public:
	string simplifyPath(string path) {

		bool isStart = false;

		std::vector<string> dirs;
		
		std::string dir;

		for (int i = 0; i < path.size(); i++)
		{
			if ('/' == path[i])
			{
				if (false == isStart)
				{
					isStart = true;
				}
				else if (true == isStart)
				{
					if (0 < dir.size())
					{
						dirs.push_back(std::move(dir));
					}
					isStart = false;
				}
				continue;
			}
			else if ('.' == path[i])
			{
				if ('.' == path[i + 1])
				{
					if(dirs.size())
						dirs.pop_back();
					i++;
				}
				else if ('/' == path[i + 1])
				{
					isStart = true;
					i++;
				}
				continue;
			}
			else
			{
				dir += path[i];
			}
		}

		string ret = "/";

		for (int i = 0; i < dirs.size(); i++)
		{
			ret += dirs[i];

			if (i < dirs.size() - 1)
			{
				ret += '/';
			}
			
		}

		return ret;

	}
};


