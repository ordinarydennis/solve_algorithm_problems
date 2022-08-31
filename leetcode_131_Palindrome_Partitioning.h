class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
       
        vector<string> currentList;
        
        dfs(result, s, 0, currentList);
        
        return result;
    }

    void dfs(vector<vector<string>>& result, string& s, int start, vector<string>& currentList) 
    {
        if (start >= s.length()) 
            result.push_back(currentList);
        
        for (int end = start; end < s.length(); end++)
        {
            if (isPalindrome(s, start, end))
            {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));

                dfs(result, s, end + 1, currentList);

                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int low, int high)
    {
        while (low < high)
        {
            if (s[low++] != s[high--]) 
                return false;
        }
        return true;
    }
};


class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		if (s.empty()) return ret;

		vector<string> path;
		dfs(0, s, path, ret);

		return ret;
	}

	void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret)
	{
		if (index == s.size())
		{
			ret.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i)
		{
			if (isPalindrome(s, index, i))
			{
				path.push_back(s.substr(index, i - index + 1));
				dfs(i + 1, s, path, ret);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(const string& s, int start, int end)
	{
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};