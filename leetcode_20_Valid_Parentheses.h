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

        for (const auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                ov.push_back(c);
            }
            else
            {
                int last = ov.size() - 1;

                if (0 > last)
                {
                    return false;
                }

                if (m[c] == m[ov[last]])
                {
                    ov.erase(ov.begin() + last);
                }
                else
                {
                    return false;
                }
            }
        }

        return ov.empty();

    }
};