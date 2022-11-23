class Solution {
public:
    bool checkOnesSegment(string s) {

        return std::string::npos == s.find("01");

    }
};