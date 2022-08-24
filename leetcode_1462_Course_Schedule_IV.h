class Solution {

	bool dfs(int start, int dest, const std::unordered_map<int, vector<int>>& preReqMat, std::set<int>& chk)
	{
		if (chk.count(start))
		{
			return false;
		}

		chk.insert(start);

		const auto& it = preReqMat.find(start);

		if (preReqMat.end() == it)
		{
			return false;
		}

		const vector<int>& list = it->second;

		for (int d : list)
		{
			if (d == dest)
			{
				return true;
			}

			bool find = dfs(d, dest, preReqMat, chk);

			if (find)
			{
				return true;
			}
		}

		return false;
	}

public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

		vector<bool> ret;
		std::unordered_map<int, vector<int>> preReqMat;

		for (const auto& preReq : prerequisites)
		{
			preReqMat[preReq[0]].push_back(preReq[1]);
		}

		for (const auto& q : queries)
		{
			std:set<int> chk;
			bool find = dfs(q[0], q[1], preReqMat, chk);
			ret.push_back(find);
		}

		return ret;

	}
};