class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {

		int player1 = 0;
		int player2 = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			int* player = (i & 1) ? &player2 : &player1;

			*player += nums[i];
		}

		return player2 <= player1;
	}
};