class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {

		unordered_map<int, int> numMap;

		for (const auto n : nums)
		{
			auto it = numMap.find(n);
			if (it == numMap.end())
			{
				numMap.emplace(n, 1);
			}
			else
			{
				it->second++;
			}
		}

		multimap<int, int, greater<int>> mmap;

		for (const auto& [n, c] : numMap)
		{
			mmap.insert(make_pair(c, n));
		}

		vector<int> ret;

		ret.reserve(k);

		int i = 0;
		for (auto it = mmap.begin(); it != mmap.end(); ++it)
		{
			i++;
			ret.push_back(it->second);
			if (k <= i)
				break;
		}

		return std::move(ret);

	}
};