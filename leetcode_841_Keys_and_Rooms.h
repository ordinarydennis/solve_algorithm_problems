class Solution {

	bool findRoom(vector<vector<int>>& rooms, int roomIndex, int visitCount, std::unordered_map<int, bool>& checker)
	{
		if (rooms.size() == visitCount)
		{
			return true;
		}

		auto it = checker.find(roomIndex);

		if (checker.end() != it)
		{
			return false;
		}

		checker.emplace(roomIndex, true);

		const auto& keyList = rooms[roomIndex];

		for (const int roomIndexFromKey : keyList)
		{
			if (true == findRoom(rooms, roomIndexFromKey, visitCount + 1, checker))
			{
				return true;
			}
		}

		return false;
	}


public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {

		std::unordered_map<int, bool> checker;

		checker.emplace(0, true);

		return findRoom(rooms, 0, 1, checker);

	}
};



[[1, 3], [3, 0, 1], [2], [0]]