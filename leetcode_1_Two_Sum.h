class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ret;
        ret.reserve(2);
        
        auto listSize = static_cast<int>(nums.size());
        
        for(int i = 0; i < listSize; ++i)
        {
            for(int a = i+1; a < listSize; ++a)
            {
                if( target == nums[i] +  nums[a] )          
                {
                    ret.emplace_back(i);
                    ret.emplace_back(a);
                    
                    break;
                }
            }
            
            if(false == ret.empty())
            {
                break;
            }
        }
        
        return std::move(ret);
        
    }
};