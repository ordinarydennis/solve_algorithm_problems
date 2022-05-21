class Solution {
private:
    unordered_map<int, int> visited;

public:
    int integerReplacement(int n) {

        if (n == 1)
            return 0;

        
        if (visited.count(n) == 0)
        {
            if (n & 1 == 1)
            {
                visited[n] = 2 + min(
                    integerReplacement(n / 2), 
                    integerReplacement(n / 2 + 1)
                );
            }
            else
            {
                visited[n] = 1 + integerReplacement(n / 2);
            }
        }
        
        return visited[n];
    }
};

class Solution {
private:
    unordered_map<int, int> visited;

    int dfs(int n)
    {
        if (visited.count(n) == 0)
        {
            if (n & 1 == 1)
            {
                visited[n] = 1 + min(
                    dfs(n + 1),
                    dfs(n - 1)
                );
            }
            else
            {
                visited[n] = 1 + integerReplacement(n / 2);
            }
        }
    }

public:
    int integerReplacement(int n) {

        if (n == 1)
            return 0;


        dfs(n);


        return visited[n];
    }
};