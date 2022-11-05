class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {

		vector<int> v;

		v.resize(releaseTimes.size());

		v[0] = releaseTimes[0];

		vector<int> mi;

		int max = v[0];

		for (int i = 1; i < releaseTimes.size(); i++)
		{
			int g = releaseTimes[i] - releaseTimes[i - 1];

			v[i] = g;

			if (max == g)
			{
				mi.push_back(i);
			}
			else if (max < g)
			{
				max = g;

				mi.clear();
				mi.push_back(i);
			}
		}

		if (mi.size() == 1)
		{
			return mi[0];
		}
		else
		{

			return keysPressed[mi[mi.size() - 1]];

			std::set<char> s;

			for (int i : mi)
			{
				s.emplace(keysPressed[i]);
			}
			


			return *s.rbegin();

		}

	}
};
