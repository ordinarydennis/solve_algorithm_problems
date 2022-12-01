class Solution {
public:
    string sortSentence(string s) {

        std::map<char, std::string> m;

        std::string w;

        for (int i = 0; i < s.size(); i++)
        {
            if (' ' == s[i])
            {
                m.emplace(s[i-1], std::move(w));
            }
            else
            {
                if ('0' <= s[i] && s[i] <= '9')
                {
                    continue;
                }
                w += s[i];
            }
        }

        m.emplace(s[s.size() - 1], std::move(w));

        string ret;

        for (const auto& [_, word] : m)
        {
            ret += word + " ";
        }

        ret.erase(ret.size() - 1);

        return ret;
    }
};