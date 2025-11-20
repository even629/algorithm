#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>

using std::unordered_map;
using std::vector;
using std::pair;
using std::queue;

class Solution {
    public:
	vector<vector<int> > get_index_vec(int n)
	{
		int i = n - 1, j = 0, total = 1;
		bool left = false;
		vector<vector<int> > index_vec =
			vector<vector<int> >(n, vector<int>(n));

		while (total <= n * n) {
			index_vec[i][j] = total;
			total++;
			if (j == n - 1 && left == false) {
				left = true;
				i--;
				continue;
			}
			if (j == 0 && left == true) {
				left = false;
				i--;
				continue;
			}
			if (left) {
				j--;
			} else {
				j++;
			}
		}
		return index_vec;
	}
	int snakesAndLadders(vector<vector<int> > &board)
	{
		int i, j, n = board.size();
		vector<vector<int> > index = get_index_vec(n);
		int res = 0;
		int last = 0;
		unordered_map<int, int> ladders_or_snakes;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (board[i][j] != -1) {
					ladders_or_snakes[index[i][j]] =
						board[i][j];
				}
			}
		}
		queue<pair<int, int> > que; // {位置, 步数}
		unordered_set<int> visited;
		int next;
		que.push({ 1, 0 });
		visited.insert(1);

		while (!que.empty()) {
			auto [curr, step] = que.front();
			que.pop();

			if (curr == n * n)
				return step;
			// 模拟每一步
			for (int dice = 1; dice <= 6; dice++) {
				next = curr + dice;
				if (next > n * n)
					break;

				if (ladders_or_snakes.count(next)) {
					next = ladders_or_snakes[next];
				}

				if (!visited.count(next)) {
					visited.insert(next);
					que.push({ next, step + 1 });
				}
			}
		}
		return -1;
	}
};

// [-1,-1,-1,-1,-1,-1]
// [-1,-1,-1,-1,-1,-1]
// [-1,-1,-1,-1,-1,-1]
// [-1,35,-1,-1,13,-1]
// [-1,-1,-1,-1,-1,-1]
// [-1,15,-1,-1,-1,-1]]
