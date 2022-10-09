class Solution {
public:
    string removeDuplicates(string s) {

        char pre = ' ';

        for (int i = 0; i < s.size(); i++)
        {
            if (0 == i)
            {
                pre = s[i];
                continue;
            }

            if (pre == s[i])
            {
                s.erase(i - 1, 2);
                i = std::max(i - 3, -1);
                continue;
            }

            pre = s[i];

        }

        return s;

    }
};
