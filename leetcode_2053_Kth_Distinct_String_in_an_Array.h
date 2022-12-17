class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        std::unordered_map<string, std::pair<int,int>> m;

        for (int i = 0 ; i < arr.size(); i++)
        {
            auto it = m.find(arr[i]);

            if (m.end() == it)
            {
                m.emplace(arr[i], {1, i});
            }
            else
            {
                auto& p = m[arr[i]];
                p.first++;
            }
            
        }

        string ret;

        for (const auto& [s, pair] : m)
        {
            if (1 != pair.first)
            {
                continue;
            }

            if (i == k)
            {
                ret = std::move(arr[i]);
                break;
            }
        }

        return ret;

    }
};