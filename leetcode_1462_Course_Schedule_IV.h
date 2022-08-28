class Solution {

    vector<vector<int>>dp;

    bool dfs(int start, int end, const std::unordered_map<int, std::vector<int>>& mat)
    {
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
        const auto it = mat.find(start);

        if (mat.end() == it)
        {
            return dp[start][end] = 0;
            return false;
        }

        const auto& list = it->second;

        for (const auto& n : list)
        {
            if (n == end)
            {
                dp[start][end] = 1;
                return true;
            }

            bool find = dfs(n, end, mat);

            if (find)
            {
                dp[start][end] = 1;
                return find;
            }
        }

        return dp[start][end] = 0;
        return false;
    }


public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<bool> ret;

        std::unordered_map<int, std::vector<int>> mat;

        dp.resize(numCourses, vector<int>(numCourses, -1));

        for (const auto& preReq : prerequisites)
        {
            mat[preReq[1]].push_back(preReq[0]);
            dp[preReq[1]][preReq[0]] = 1;
        }

        for (const auto& q : queries)
        {
            int end = q[0];
            int start = q[1];

            ret.push_back(dfs(start, end, mat));
        }

        return ret;
    }
};