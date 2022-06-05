class Solution {

    int count = 0;

    void traversal(vector<int>& nums, int pos, int sum, int target)
    {
        if (pos == nums.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }

        traversal(nums, pos + 1, sum - nums[pos], target);
        traversal(nums, pos + 1, sum + nums[pos], target);

    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        traversal(nums, 0, 0, target);

        return count;
    }
};


class Solution {

    int count = 0;

    int find(int p, vector<int>& nums, int sum, vector<unordered_map<int, int>>& mem) {

        if (p == nums.size()) return sum == 0;

        auto it = mem[p].find(sum);

        if (it != mem[p].end()) return it->second;

        return mem[p][sum] = find(p + 1, nums, sum + nums[p], mem) + find(p + 1, nums, sum - nums[p], mem);

    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<unordered_map<int, int>> mem(nums.size());

        return find(0, nums, target, mem);
    }
};


-1 + 1 + 1 + 1 + 1 = 3
+ 1 - 1 + 1 + 1 + 1 = 3
+ 1 + 1 - 1 + 1 + 1 = 3
+ 1 + 1 + 1 - 1 + 1 = 3
+ 1 + 1 + 1 + 1 - 1 = 3

+ 1 + 1 + 1 + 1 - 1 = 3
+ 1 + 1 + 1 + 1 + 1 = 4

+ 1 + 1 + 1 + 1 + 1 = 3
+ 1 + 1 + 1 + 1 - 1 = 4

p : 4
sum : 5
mem[4][5] =  0

p : 4
sum : 3
mem[4][3] = 0

p : 3
sum : 4
mem[4][4] = 0

p : 3
sum : 3
mem[4][3] = 0

int findTargetSumWays(vector<int>& nums, int S) {
    vector<unordered_map<int, int>> mem(nums.size());
    return find(0, nums, S, mem);
}


int find(int p, vector<int>& nums, int sum, vector<unordered_map<int, int>>& mem) {

    if (p == nums.size()) return sum == 0;
    
    auto it = mem[p].find(sum);
    
    if (it != mem[p].end()) return it->second;
    
    return mem[p][sum] = find(p + 1, nums, sum + nums[p], mem) + find(p + 1, nums, sum - nums[p], mem);

}

+ 1 + 1 + 1 + 1 + 1 = 5
+ 1 + 1 + 1 + 1 - 1 = 3