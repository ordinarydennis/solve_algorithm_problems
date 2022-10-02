
class Solution {
    
    vector<string> split(string input, char delimiter) {
        
        vector<string> answer;
        
        stringstream ss(input);
        
        string temp;

        while (getline(ss, temp, delimiter))
        {
            answer.push_back(temp);
        }

        return answer;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        std::vector<string> list1 = split(s1, ' ');
        std::vector<string> list2 = split(s2, ' ');

        std::vector<string> ret;
        
        for (const auto& s : list2)
        {
            auto it = std::find(list1.begin(), list1.end(), s);

            if (it == list1.end())
            {
                ret.push_back(s);
            }
        }
    
        return ret;
    }
};