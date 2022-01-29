class Solution {
public:
    bool isValid(string s) {

        vector<char> ov;

        map<char, int> m = {
            {'(',1},
            {')',1},
            {'{',2},
            {'}',2},
            {'[',3},
            {']',3},

        };

        int i = 0;
        for (const auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                ov.push_back(c);
            }
            else
            {
                if (m[c] != m[ov[ov.size() - 1]])
                {
                    return false;
                }

                ov.erase(s.begin() + i);
            }
        }

        return true;

    }
};