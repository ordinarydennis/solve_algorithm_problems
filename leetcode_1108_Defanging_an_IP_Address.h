class Solution {
public:
	string defangIPaddr(string address) {

		string str;

		str.reserve(address.size() + 10);

		for (const char c : address)
		{
			if ('.' == c)
			{
				str += '[';
			}
			
			str += c;

			if ('.' == c)
			{
				str += ']';
			}

		}

		return str;
	}
};