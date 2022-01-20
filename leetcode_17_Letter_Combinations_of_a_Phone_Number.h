class Solution {

	map<char, string> m = {
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"}
	};


	void dfp(const string& digits, int count, string& rStr, vector<string>& strList)
	{
		if (digits.size() == count)
		{
			strList.push_back(rStr);
			return;
		}

		const auto& c = digits[count];

		for (const auto c : m[c])
		{
			rStr += c;
			dfp(digits, count + 1, rStr, strList);
			rStr.erase(rStr.size() - 1, 1);
		}
	}

public:
	vector<string> letterCombinations(string digits) {

		vector<string> retList;
		if (digits.empty())
		{
			return retList;
		}

		string str;
		dfp(digits, 0, str, retList);

		return retList;
	}
};