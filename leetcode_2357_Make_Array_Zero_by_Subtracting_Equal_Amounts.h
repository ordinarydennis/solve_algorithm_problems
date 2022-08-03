class Solution {
public:
	int minimumOperations(vector<int>& nums) {

		std::map<int, int> map;

		for (const int n : nums)
		{
			if (0 != n)
			{
				map.emplace(n, n);
			}

		}

		int ret = 0;

		while (map.size())
		{
			const auto& it = map.begin();

			int num = it->second;

			for (auto it = map.begin(); it != map.end();)
			{
				it->second -= num;

				if (0 == it->second)
				{
					it = map.erase(it);
				}
				else
				{
					++it;
				}
			}

			ret++;
		}

		return ret;
	}
};