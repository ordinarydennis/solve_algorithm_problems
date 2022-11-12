class Solution {
public:
    string maximumTime(string time) {

        for (int i = 0; i < time.size(); i++)
        {
            if ('?' != time[i])
            {
                continue;
            }

            if (0 == i)
            {
                if ('?' == time[i + 1])
                {
                    time[i] = '2';
                    time[i + 1] = '4';
                    i++;
                }
                else if ('4' <= time[i + 1])
                {
                    time[i] = '1';
                }
                else
                {
                    time[i] = '2';
                }
            }
            else if (1 == i)
            {
                if ('1' == time[i - 1] || '0' == time[i - 1])
                {
                    time[i] = '9';
                }

                if ('2' == time[i - 1])
                {
                    time[i] = '3';
                }
            }
            else if (3 == i)
            {
                time[i] = '5';
            }
            else if (4 == i)
            {
                time[i] = '9';
            }
        }

        return time;

    }
};