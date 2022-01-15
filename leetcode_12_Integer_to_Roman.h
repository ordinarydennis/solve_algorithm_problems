class Solution {
public:
    string intToRoman(int num) {
		
		string ret;

		int pos = 0;

		vector<pair<char,char>> v;

		v.push_back(pair<char,char>('I','V'));
		v.push_back(pair<char,char>('X','L'));
		v.push_back(pair<char,char>('C','D'));
		v.push_back(pair<char,char>('M',' '));

		while(1)
		{
			int num2 = num % 10;

			if(0 == num2)
			{
				pos++;
				num = num / 10;
				if(num <= 0)
				{
					break;
				}
				continue;
			}

			const auto& p = v[pos];

			if(num2 <= 3)
			{
				for(int i =0 ; i < num2; i++)
				{
					ret.insert(ret.begin(), p.first);
				}
			}
			else if(num2 < 5)
			{
				string s;		
				s.push_back(p.first);
				s.push_back(p.second);
				ret.insert(ret.begin(), s.begin(), s.end());
			}
			else if(num2 == 5)
			{
				ret.insert(ret.begin(), p.second);
			}
			else if(num2 < 9)
			{
				string s;
				s.push_back(p.second);
				for(int i =0; i < num2 - 5; i++)
				{
					s.push_back(p.first);
				}

				ret.insert(ret.begin(), s.begin(), s.end());
			}
			else //9
			{
				string s;
				s.push_back(p.first);
				s.push_back(v[pos + 1].first);
				ret.insert(ret.begin(), s.begin(), s.end());
			}

			pos++;

			num = num / 10;
			
			if(num <= 0)
			{
				break;
			}
		}

		return ret;

    }
};