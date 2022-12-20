class Solution {
public:
	int countPoints(string rings) {

		std::array<std::unordered_set<char>, 10> arr;

		for (int i = 1; i < rings.size();)
		{
			auto& ss = arr[rings[i] - '0'];

			ss.insert(rings[i - 1]);

			i += 2;
		}

		int ret = 0;

		for (const auto& us : arr)
		{
			if (3 == us.size())
			{
				ret++;
			}
		}

		return ret;
	}
};