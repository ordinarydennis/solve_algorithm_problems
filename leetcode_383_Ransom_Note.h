class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		for (int i = 0; i < ransomNote.size(); i++)
		{
			auto it = std::find(magazine.begin(), magazine.end() ransomNote[i]);

			if (magazine.end() == it)
				return false;

			*it = ' ';
		}

		return true;
	}
};