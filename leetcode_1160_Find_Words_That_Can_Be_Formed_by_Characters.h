class Solution {

	std::unordered_map<char, int> makeMap(const std::string s)
	{
		std::unordered_map<char, int> cm;

		for (const char c : s)
		{
			if (cm.count(c))
			{
				cm[c]++;
			}
			else
			{
				cm.emplace(c, 1);
			}
		}

		return cm;
	}


public:
	int countCharacters(vector<string>& words, string chars) {

		auto cm = makeMap(chars);

		int ret = 0;

		for (int i = 0; i < words.size(); i++)
		{
			auto wm = makeMap(words[i]);

			bool isFind = true;

			for (const auto& [w, count] : wm)
			{
				if (0 == cm.count(w))
				{
					isFind = false;
					break;
				}

				if (cm[w] < count)
				{
					isFind = false;
					break;
				}
			}

			if (isFind && words[i].size())
			{
				ret += words[i].size();
			}
		}

		return ret;
	}
};


["cat", "bt", "hat", "tree"]
"atach"

a 2
t 1
c 1
h 1

cat

["dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin", 
"ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb", 
"ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl", 
"boygirdlggnh", 
"xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx", 
"nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop", 
"hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx", 
"juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr", 
"lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo", "oxgaskztzroxuntiwlfyufddl", 
"tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp", "qnagrpfzlyrouolqquytwnwnsqnmuzphne", "eeilfdaookieawrrbvtnqfzcricvhpiv", 
"sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz", "yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue", 
"hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv", "cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo",
"teyygdmmyadppuopvqdodaczob", "qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs", 
"qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"]

"usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp"