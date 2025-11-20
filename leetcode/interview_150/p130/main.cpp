#include <vector>
#include <stack>
#include <utility>

using std::stack;
using std::vector;
using std::pair;

class Solution {
    private:
	bool is_boundary(int m, int n, int i, int j)
	{
		if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
			return true;
		}
		return false;
	}

    public:
	void solve(vector<vector<char> > &board)
	{
		int m, n;
		m = board.size();
		n = board[0].size();
		vector<vector<bool> > visited =
			vector<vector<bool> >(m, vector<bool>(n, false));
		stack<pair<int, int> > st;
		vector<pair<int, int> > chg;
		bool chg_enable;
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (board[i][j] == 'X' || visited[i][j]) {
					continue;
				}
				st.push({ i, j });
				chg.clear();
				chg_enable = true;
				while (!st.empty()) {
					auto [curr_i, curr_j] = st.top();
					st.pop();
					visited[curr_i][curr_j] = true;
					chg.push_back({ curr_i, curr_j });
					if (is_boundary(m, n, curr_i, curr_j)) {
						chg_enable = false;
					}
					// 上
					if (curr_i - 1 >= 0 &&
					    board[curr_i - 1][curr_j] == 'O' &&
					    !visited[curr_i - 1][curr_j]) {
						st.push({ curr_i - 1, curr_j });
					}
					// 下
					if (curr_i + 1 < m &&
					    board[curr_i + 1][curr_j] == 'O' &&
					    !visited[curr_i + 1][curr_j]) {
						st.push({ curr_i + 1, curr_j });
					}
					// 左
					if (curr_j - 1 >= 0 &&
					    board[curr_i][curr_j - 1] == 'O' &&
					    !visited[curr_i][curr_j - 1]) {
						st.push({ curr_i, curr_j - 1 });
					}
					// 右
					if (curr_j + 1 < n &&
					    board[curr_i][curr_j + 1] == 'O' &&
					    !visited[curr_i][curr_j + 1]) {
						st.push({ curr_i, curr_j + 1 });
					}
				}
				if (chg_enable) {
					for (auto [pi, pj] : chg) {
	                    board[pi][pj] = 'X';
					}
				}
			}
		}
	}
};
