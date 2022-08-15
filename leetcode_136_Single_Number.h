class Solution {
public:
    int singleNumber(vector<int>& nums) {

        std::unordered_map<int, int> chk;

        for (int n : nums)
        {
            if (chk.count(n))
            {
                chk[n]++;
            }
            else
            {
                chk[n] = 1;
            }
        }

        int ret = 0;

        for (const auto& [n, count] : chk)
        {
            if (1 == count)
            {
                ret = n;
            }
        }

        return ret;

    }
};