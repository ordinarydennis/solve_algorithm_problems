
/*
My solution
This problem is solved using dp.
First, create a dp to store distance to 0.
basically, if the value of the cell of the matrix is 0, fill the cell of the dp with 0.
in the first loop, if the upper or left cells are 0, the value of the current cell of the dp must be 1, 
otherwise, fill the current cell with a value that adds 1 to the smaller either the upper or the left cell.
in the second loop, as the same way, if the lower or right cells are 0, the value of the current cell of the dp must be 1. 
otherwise, fill the current cell with a value that adds 1 to the smaller either the lower or the right cell.
*/

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		int row = mat.size();
		int column = mat[0].size();

		vector<vector<int>> dist(row, vector<int>(column, 10001));

		//check up and left
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < column; b++)
			{
				if (0 == mat[a][b])
				{
					dist[a][b] = 0;
					continue;
				}

				if (0 < a)
				{
					dist[a][b] = std::min(
						dist[a][b],
						dist[a - 1][b] + 1
					);
				}

				if (0 < b)
				{
					dist[a][b] = std::min(
						dist[a][b],
						dist[a][b - 1] + 1
					);
				}
			}
		}

		//check down and right
		for (int a = row - 1; 0 <= a; a--)
		{
			for (int b = column - 1; 0 <= b; b--)
			{
				if (0 == mat[a][b])
				{
					dist[a][b] = 0;
					continue;
				}


				if (a < row - 1)
				{
					dist[a][b] = std::min(
						dist[a][b],
						dist[a + 1][b] + 1
					);
				}

				if (b < column - 1)
				{
					dist[a][b] = std::min(
						dist[a][b],
						dist[a][b + 1] + 1
					);
				}
			}
		}

		return dist;
	}
};




//Approach 2: Using BFS
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows == 0)
			return matrix;
		int cols = matrix[0].size();
		vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					dist[i][j] = 0;
					q.push({ i, j }); //Put all 0s in the queue.
				}
			}
		}

		int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
				if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
					if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
						dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
						q.push({ new_r, new_c });
					}
				}
			}
		}
		return dist;
	}
};

//Approach 3: Dynamic Programming
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		
		if (rows == 0)
			return matrix;
		
		int cols = matrix[0].size();
		
		vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX - 100000));

		//First pass: check for left and top
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 0) {
					dist[i][j] = 0;
				}
				else
				{
					if (i > 0)
						dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);

					if (j > 0)
						dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
				}
			}
		}

		//Second pass: check for bottom and right
		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = cols - 1; j >= 0; j--)
			{
				if (i < rows - 1)
					dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);

				if (j < cols - 1)
					dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
			}
		}
		return dist;
	}
};