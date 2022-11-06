class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s1;
        string s2;

        for (const auto w : word1)
        {
            s1 += w;
        }

        for (const auto w : word2)
        {
            s2 += w;
        }


        return s1 == s2;

    }
};