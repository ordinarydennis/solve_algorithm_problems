class Solution {
public:
	int strStr(string haystack, string needle) {

		char find = needle[0];

		int index = -1;

		for (int i = 0; i < haystack.size(); i++)
		{
			if (haystack[i] != find)
				continue;

			bool check = true;

			for (int a = 1; a < needle.size(); a++)
			{
				if (haystack[i + a] != needle[a])
				{
					check = false;
					break;
				}
			}

			if (false == check)
				continue;

			index = i;
			break;

		}

		return index;
	}
};