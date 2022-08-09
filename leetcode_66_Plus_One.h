class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int lastIndex = digits.size() - 1;

        while (1)
        {
            if (lastIndex < 0)
            {
                digits.insert(digits.begin(), digits[0] + 1);
                break;
            }

            if (9 == digits[lastIndex])
            {
                digits[lastIndex] = 0;
                
                --lastIndex;
            }
            else
            {
                digits[lastIndex]++;
                break;
            }
        }

        return digits;

    }
};