class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int ret = 0;

        for (const auto& s : words)
        {
            auto i = s.find(pref);

            if (0 == i)
            {
                ret++;
            }
        }

        return ret;
    }
};