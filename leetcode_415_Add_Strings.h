class Solution {
public:
    string addStrings(string num1, string num2) {

        string ret(std::stoi(num1) + std::stoi(num2));

        return ret.to_string();

    }
};
}