#include <queue>
#include <tuple>
#include <vector>

using std::priority_queue;
using std::tuple;
using std::vector;

typedef priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       std::greater<tuple<int, int, int>>>
    min_heap;
class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {

    int m = heightMap.size();
    int n = heightMap[0].size();
    int res = 0;
    min_heap pq;

    vector<vector<bool>> visit(m, vector<bool>(n, false));

    if (m <= 2 || n <= 2) {
      return 0;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          pq.push({heightMap[i][j], i, j});
          visit[i][j] = true;
        }
      }
    }

    int dirs[] = {-1, 0, 1, 0, -1};
    while (!pq.empty()) {
      auto [h, x, y] = pq.top();
      pq.pop();
      // 当前值的上下左右
      for (int k = 0; k < 4; ++k) {
        int nx = x + dirs[k];
        int ny = y + dirs[k + 1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
          if (heightMap[nx][ny] < h) {
            res += h - heightMap[nx][ny];
          }
          visit[nx][ny] = true;
          pq.push({std::max(heightMap[nx][ny], h), nx, ny});
        }
      }
    }

    return res;
  }
};
