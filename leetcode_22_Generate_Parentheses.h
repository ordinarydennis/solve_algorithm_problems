class Solution {
public:
    vector<string> generateParenthesis(int n) {

        max = n;
        string s;
        dfs(s, 0, 0, 0);

        return result;
    }

private:
    void dfs(string s, int leftCount, int rightCount, int openCount)
    {
        if (max <= rightCount)
        {
            result.push_back(s);
            return;
        }

        if (leftCount < max)
        {
            dfs(s + '(', leftCount + 1, rightCount, openCount + 1);
        }

        if (0 < openCount && rightCount < max)
        {
            dfs(s + ')', leftCount, rightCount + 1, openCount - 1);
        }

        return;

    }

    int max = 0;
    vector<string> result;
};
