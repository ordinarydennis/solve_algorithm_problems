class Solution {
public:
    int firstUniqChar(string s) {

        std::map<int, char> indexCharmap;

        std::unordered_map<char, int> charIndexMap;


        for (int i = 0; i < s.size(); i++)
        {

            auto it = charIndexMap.find(s[i]);

            if (it == charIndexMap.end())
            {
                charIndexMap.emplace(s[i], i);
                indexCharMap.emplace(i, s[i]);
            }
            else
            {
                indexCharMap.erase(i);
            }



        }


        return indexCharMap.size() == 0 ? -1 : indexCharMap.begin()->first;

    }
};