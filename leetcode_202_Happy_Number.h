class Solution {
public:
    bool isHappy(int n) {

        unsigned int num = n;

        set<int> chk;

        while (1)
        {
            unsigned int sum = 0;

            if (chk.count(num))
            {
                return false;
            }

            chk.insert(num);

            while (num)
            {
                unsigned int lastNum = num % 10;

                sum += (lastNum * lastNum);

                num /= 10;
            }

            if (1 == sum)
            {
                return true;
            }

            num = sum;

        }
        
    }
};
