
//마지막 저장
//맵으로 저장
//이미 있는 문자가 나오면 사이즈 저장하고 클리어 
//비었으면 추가 
"dvdf"
"ckilbkd"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    std::map<char, int> m;
    char lastc = '0';
    int maxSize = 0;
    for(const auto& c : s)
    {
        auto mIt = m.find(c);
        if(m.end() != mIt)
        {
			if (maxSize < m.size())
			{
				maxSize = m.size();
			}
			m.clear();
			m.emplace(c, 1);

			lastc = c;
            continue;
        }

        m.emplace(c, 1);
		lastc = c;

    }


    if(maxSize == 0 || maxSize < m.size())
    {
       maxSize = m.size();
    }

    return maxSize;

    }
};


