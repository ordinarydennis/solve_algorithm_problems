class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto it = std::find(nums.begin(), nums.end(), target);

        if (nums.end() == it)
        {
            return -1;
        }
        else
        {
            return it - nums.begin();
        }

    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int begin = 0;
        int end = nums.size() - 1;

        while (begin <= end)
        {
            int index = begin + ((end - begin)/ 2);

            if (nums[index] == target)
            {
                return index;
            }
            else if (nums[index] < target)
            {
                begin = index  + 1;
            }
            else 
            {
                end = index - 1;
            }
        }

        return -1;
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {

        int begin = nums.begin();
        int end = nums.end();
        
        while (begin <= end)
        {
            int index = begin + (end - begin) / 2;

            if (nums[index] == target)
            {
                return index;
            }
            else if (nums[index] < target)
            {
                begin = index + 1;
            }
            else
            {
                end = index - 1;
            }

        }
        
        
        

        return -1;


    }
};