class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		std::map<int, vector<int>> chk;

		for (const auto& preReq : prerequisites)
		{
			chk[preReq[0]].push_back(preReq[1]);
		}

		for (const auto& preReq : prerequisites)
		{
			const auto& it = chk.find(preReq[0]);

			const auto& preReqList = it->second;

			for (const int req : preReqList)
			{
				const auto& it2 = chk.find(req);

				if (it2 == chk.end())
				{
					continue;
				}

				const auto& preReqList2 = it2->second;

				auto findIt = std::find(preReqList2.begin(), preReqList2.end(), preReq[0]);

				if (preReqList2.end() != findIt)
				{
					return false;
				}
			}
		}

		return true;

	}
};