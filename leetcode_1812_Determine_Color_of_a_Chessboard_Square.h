class Solution {
public:
	bool squareIsWhite(string coordinates) {

		int x = coordinates[0] - 'a' + 1;
		int y = coordinates[1] - '1' + 1;;

		return (0 == x % 2 && 0 == y % 2 || 0 != x % 2 && 0 != y % 2) ? false : true;
	}
};