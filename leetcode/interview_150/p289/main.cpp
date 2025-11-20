#include <vector>
using std::vector;

class Solution {
    public:
	void get_cnt(vector<vector<int> > &board, int &live_cell_cnt, int i, int j)
	{
		int m = board.size(), n = board[0].size();
		live_cell_cnt = 0;

		// 上
		if (i > 0) {
			if (board[i - 1][j] == 1) {
				live_cell_cnt++;
			}
		}
		// 下
		if (i < m - 1) {
			if (board[i + 1][j] == 1) {
				live_cell_cnt++;
			}
		}
		// 左
		if (j > 0) {
			if (board[i][j - 1] == 1) {
				live_cell_cnt++;
			}
		}
		//右
		if (j < n - 1) {
			if (board[i][j + 1] == 1) {
				live_cell_cnt++;
			}
		}
		// 左上角
		if (i > 0 && j > 0) {
			if (board[i - 1][j - 1] == 1) {
				live_cell_cnt++;
			}
		}
		// 右上角
		if (i > 0 && j < n - 1) {
			if (board[i - 1][j + 1] == 1) {
				live_cell_cnt++;
			}
		}
		// 左下角
		if (i < m - 1 && j > 0) {
			if (board[i + 1][j - 1] == 1) {
				live_cell_cnt++;
			}
		}
		// 右下角
		if (i < m - 1 && j < n - 1) {
			if (board[i + 1][j + 1] == 1) {
				live_cell_cnt++;
			}
		}
	}
	void gameOfLife(vector<vector<int> > &board)
	{
		vector<vector<int> > original(board);
		int m = board.size(), n = board[0].size();
		int i, j, live_cell_cnt;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				get_cnt(original, live_cell_cnt, i, j);
				if (original[i][j] == 1) {
					if (live_cell_cnt < 2) {
						// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
						board[i][j] = 0;
					} else if (live_cell_cnt == 2 || live_cell_cnt == 3) {
						// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
						board[i][j] = 1;
					} else {
						// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
						board[i][j] = 0;
					}
				} else {
					if (live_cell_cnt == 3) {
						// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
						board[i][j] = 1;
					}
				}
			}
		}
	}
};
