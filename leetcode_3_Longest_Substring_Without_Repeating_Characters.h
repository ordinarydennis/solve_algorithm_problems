class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> m;

        int ret = 0;

        int size = s.size();

        for (int i = 0; i < size; i++)
        {
            char c = s[i];

            const auto& it = m.find(c);
            if (m.end() == it)
            {
                m.emplace(c, i);
            }
            else
            {
                if (ret < m.size())
                {
                    ret = m.size();
                }

                i = it->second;
                m.clear();
            }
        }

        if (ret < m.size())
        {
            ret = m.size();
        }

        return ret;

    }
};