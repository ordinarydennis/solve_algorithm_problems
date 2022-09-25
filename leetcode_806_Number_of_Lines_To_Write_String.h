class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {

        int rSize = 0;
        int rCount = 1;

        for (const char c : s)
        {
            int size = widths[c - 'a'];

            if (100 < rSize + size)
            {
                rCount++;
                rSize = size;
            }
            else
            {
                rSize += size;
            }
        }

        return std::vector<int>{rCount, rSize};

    }
};
