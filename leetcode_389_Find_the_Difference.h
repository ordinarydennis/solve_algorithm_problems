class Solution {
public:
    char findTheDifference(string s, string t) {

        char r = ' ';

		for (int i = 0; i < t.size(); i++)
        {
            auto it = std::find(s.begin(), s.end(), t[i]);

            if (s.end() == it)
            {
                r = t[i];      
            }
            else
            {
                s.erase(it);
            }
        }

        return r;
    }
};