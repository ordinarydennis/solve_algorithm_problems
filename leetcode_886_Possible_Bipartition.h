class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        if (1 == n)
            return true;

        set<int> g1;
        set<int> g2;

        g1.insert(dislikes[0][0]);
        g2.insert(dislikes[0][1]);


        for (int i = 1; i < dislikes.size(); i++)
        {

            int n1 = dislikes[i][0];
            int n2 = dislikes[i][1];


            if (0 == g1.count(n1) && 0 == g2.count(n1) && 0 == g1.count(n2) && 0 == g2.count(n2))
            {
                g1.insert(n1);
                g2.insert(n2);
                continue;
            }

            if (g1.count(n1))
            {
                if (0 == g1.count(n2))
                {
                    g2.insert(n2);
                }
                else
                {
                    return false;
                }
            }

            if (g2.count(n1))
            {
                if (0 == g2.count(n2))
                {
                    g1.insert(n2);
                }
                else
                {
                    return false;
                }
            }
        }

        return true;


    }
};