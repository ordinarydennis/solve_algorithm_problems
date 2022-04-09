// It's my answer.
class Solution {

    vector<int> jumpCount;

    void dfs(vector<int>& nums, int index)
    {
        if (nums.size() - 1 <= index)
        {
            return;
        }

        dfs(nums, index + 1);

        for (int i = 1; i <= nums[index]; i++)
        {
            if (nums.size() - 1 <= index + i)
            {
                jumpCount[index] = 1;
                break;
            }
            else
            {
                if (0 < jumpCount[index + i])
                {
                    if (0 == jumpCount[index])
                    {
                        jumpCount[index] = jumpCount[index + i] + 1;
                    }
                    else if (jumpCount[index + i] + 1 < jumpCount[index])
                    {
                        jumpCount[index] = jumpCount[index + i] + 1;
                    }
                }
            }
        }
    }


public:
    int jump(vector<int>& nums) {

        jumpCount.reserve(nums.size());
        jumpCount.resize(nums.size(), 0);

        dfs(nums, 0);

        return jumpCount[0];
    }
};


//refer to the follow link
//https://leetcode.com/problems/jump-game-ii/discuss/770191/CPP-recursive-greater-memoization-greater-O(n)-three-solution-oror-Easy-to-understand

//
class Solution {
public:

    long long int jump(vector<int>& nums, int curr, int dest, vector<int>& dp)
    {
        if (curr == dest) return 0;

        if (dp[curr] != -1) return dp[curr];

        //cout<<curr<<" ";
        long long int tmp = INT_MAX;

        for (int i = 1; i <= nums[curr]; i++)
        {
            if (i + curr > dest) break;

            tmp = min(tmp, 1 + jump(nums, curr + i, dest, dp));
        }

        dp[curr] = tmp;
        
        return tmp;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return jump(nums, 0, nums.size() - 1, dp);
    }
};

class Solution {

    vector<int> memo;

public:

    int jump(vector<int>& nums, int index)
    {
        if (nums.size() - 1 <= index)
        {
            return 0;
        }

        if (-1 != memo[index])
        {
            return memo[index];
        }

        int minCount = INT_MAX - 1;

        for (int i = 1; i <= nums[index]; i++)
        {
            minCount = std::min(minCount, 1 + jump(nums, index + i));
        }

        memo[index] = minCount;

        return memo[index];
    }

    int jump(vector<int>& nums) {

        memo.resize(nums.size(), -1);

        return jump(nums, 0);
    }
};


class Solution {

    vector<int> memo;

public:

    void jump(vector<int>& nums, int index)
    {
        if (nums.size() - 1 <= index)
        {
            return;
        }

        jump(nums, index + 1);

        int minCount = INT_MAX - 1;

        for (int i = 1; i <= nums[index]; i++)
        {
            if (nums.size() - 1 <= i + index)
            {
                minCount = 1;
                break;
            }
            else
            {
                minCount = std::min(minCount, memo[index + i] + 1);
            }
        }

        memo[index] = minCount;

        return;
    }

    int jump(vector<int>& nums) {

        memo.resize(nums.size(), 0);

        jump(nums, 0);

        return memo[0];
    }
};

//
class Solution {

    vector<int> memo;

    void jump(vector<int>& nums, int index)
    {
        if (nums.size() - 1 <= index)
        {
            return;
        }

        jump(nums, index + 1);

        if (nums.size() - 1 <= index + nums[index])
        {
            memo[index] = 1;
            return;
        }

        int minCount = INT_MAX - 1;

        for (int i = 1; i <= nums[index]; i++)
        {
            minCount = std::min(minCount, memo[index + i] + 1);
        }

        memo[index] = minCount;
    }

public:
    int jump(vector<int>& nums) {

        if (nums.size() <= 1)
        {
            return 0;
        }

        memo.resize(nums.size(), INT_MAX - 1);

        jump(nums, 0);

        return memo[0];
    }
};

