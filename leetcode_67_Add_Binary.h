class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int minSize = std::min(a.size(), b.size());

        std::string ret = a.size() < b.size() ? b : a;

        int plus = 0;

        for (int i = 0; i < minSize; i++)
        {
            int num1 = (a[i] == '0') ? 0 : 1;
            int num2 = (b[i] == '0') ? 0 : 1;

            int sum = num1 + num2 + plus;

            if (2 <= sum)
            {
                ret[i] = (2 == sum) ? '0' : '1';
                plus = 1;
            }
            else if (num1 == 0 && num2 == 0)
            {
                ret[i] = '0';
            }
            else
            {
                ret[i] = '1';
            }
        }

        if (a.size() != b.size() && 1 == plus)
        {
            ret += '1';
        }

        reverse(ret.begin(), ret.end());

        return ret;

    }
};