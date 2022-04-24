class Solution {

    void convertOnlyLowercase(string& s)
    {
        string cs;

        for (auto c : s)
        {
            if ('A' <= c && c <= 'Z')
            {
                c = c + 'a' - 'A';
            }


            if ('a' <= c && c <= 'z' || '0' <= c && c <= '9')
            {
                cs += c;
            }
        }

        s = std::move(cs);

    }

    bool isPalin(const string& str)
    {
        int s = 0;
        int e = str.size() - 1;

        while (s < e)
        {
            if (str[s++] != str[e--])
            {
                return false;
            }
        }

        return true;
    }


public:
    bool isPalindrome(string s) {

        convertOnlyLowercase(s);

        return isPalin(s);

    }
};
