#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

#define BOARD_LENGTH 9
#define SMALL_BOARD_LENGTH 3
class Solution {
    public:
	bool judge(vector<vector<char> > &board, int start_i, int start_j, int sn)
	{
		unordered_set<char> uset;
		int i, j;
		for (i = start_i; i < start_i + sn; i++) {
			for (j = start_j; j < start_j + sn; j++) {
				if (board[i][j] == '.') {
					continue;
				}
				if (uset.count(board[i][j])) {
					return false;
				}
				uset.insert(board[i][j]);
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char> > &board)
	{
		// 9*9
		int i, j;
		int n = BOARD_LENGTH;
		int sn = SMALL_BOARD_LENGTH;
		// 每一行所有元素必须只出现一次

		for (i = 0; i < n; i++) {
			unordered_set<char> uset;
			for (j = 0; j < n; j++) {
				if (board[i][j] == '.') { //不统计空白格
					continue;
				}
				if (uset.count(board[i][j])) {
					return false;
				}
				uset.insert(board[i][j]);
			}
		}
		//每列所有元素只出现一次
		for (j = 0; j < n; j++) {
			unordered_set<char> uset;
			for (i = 0; i < n; i++) {
				if (board[i][j] == '.') {
					continue;
				}
				if (uset.count(board[i][j])) {
					return false;
				}
				uset.insert(board[i][j]);
			}
		}
		// 3* 3宫格只出现一次
		for (i = 0; i < n; i += sn) {
			for (j = 0; j < n; j += sn) {
				if (!judge(board, i, j, sn)) {
					return false;
				}
			}
		}
		return true;
	}
};
