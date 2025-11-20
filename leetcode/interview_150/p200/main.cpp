#include <vector>
#include <utility>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

class Solution {
    public:
	int numIslands(vector<vector<char> > &grid)
	{
		int m, n;
		m = grid.size();
		n = grid[0].size();
		vector<vector<bool> > visited =
			vector<vector<bool> >(m, vector<bool>(n, false));
		int island_num = 0;
		int i, j;
		stack<pair<int, int> > st;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (visited[i][j] || grid[i][j] =='0') {
					continue;
				}
				st.push({ i, j });
				while (!st.empty()) {
					auto [curr_i, curr_j] = st.top();
					visited[curr_i][curr_j] = true;
					st.pop();
					// 上
					if (curr_i - 1 >= 0 &&
					    !visited[curr_i - 1][curr_j] &&
					    grid[curr_i - 1][curr_j] == '1') {
						st.push({ curr_i - 1, curr_j });
					}

					// 下
					if (curr_i + 1 < m &&
					    !visited[curr_i + 1][curr_j] &&
					    grid[curr_i + 1][curr_j] == '1') {
						st.push({ curr_i + 1, curr_j });
					}

					// 左
					if (curr_j - 1 >= 0 &&
					    !visited[curr_i][curr_j - 1] &&
					    grid[curr_i][curr_j - 1] == '1') {
						st.push({ curr_i, curr_j - 1 });
					}

					// 右
					if (curr_j + 1 < n &&
					    !visited[curr_i][curr_j + 1] &&
					    grid[curr_i][curr_j + 1] == '1') {
						st.push({ curr_i, curr_j + 1 });
					}

				}
				island_num ++;
			}
		}

		return island_num;
	}
};
