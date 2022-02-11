
//Input: board = [
//[["A", "B", "C", "E"],
//["S", "F", "C", "S"],
//["A", "D", "E", "E"]]
//"ABCB"
class Solution {

	bool ret = false;

	void dfs(vector<vector<char>>& board, string word, int col, int row, int cIndex)
	{
		if (col < 0)
		{
			return;
		}

		if (board[row].size() <= col)
		{
			return;
		}

		if (board.size() <= row)
		{
			return;
		}

		if (board[row][col] == word[cIndex])
		{
			//�� ã��
			dfs(board, word, col + 1, row, cIndex);
		}
		else
		{
			if (word.size() - 1 == cIndex)
			{
				ret = true;
				return;
			}

			//�� ã��
			dfs(board, word, col + 1, row, cIndex + 1);

			//�Ʒ� ã�� �� �� ã���� ���̴�
			dfs(board, word, col, row + 1, cIndex + 1);

			//�� ã��
			dfs(board, word, col - 1, row, cIndex + 1);
		}
	}

public:
	bool exist(vector<vector<char>>& board, string word) {

		dfs(board, word, 0, 0, 0);

		return ret;

	}
};