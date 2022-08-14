class Solution
{
public:
    string addBinary(string a, string b)
    {
        int indexA = a.size() - 1;
        int indexB = b.size() - 1;

        int carry = 0;

        string result;

        while (0 <= indexA || 0 <= indexB)
        {
            int sum = carry;

            if (0 <= indexA)
            {
                sum += a[indexA] - '0';
                indexA--;
            }

            if (0 <= indexB)
            {
                sum += b[indexB] - '0';
                indexB--;
            }

            carry = sum > 1 ? 1 : 0;

            sum = sum % 2;

            result += to_string(sum);
        }

        if (carry)
        {
            result += to_string(carry);
        }

        reverse(result.begin(), result.end());

        return result;

    }
};