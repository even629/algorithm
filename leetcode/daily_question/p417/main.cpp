#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    int i, j, k;
    int neighbor_i, neighbor_j;
    // (i-1, j) (i,j+1) (i+1,j)  (i,j-1)
    int arr[] = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> que;
    vector<vector<pair<int, int>>> vec(m, vector<pair<int, int>>(n, {-1, -1}));
    bool updated = false;
    vector<vector<int>> result;

    // 第一行和最后一行
    for (int j = 0; j < n; j++) {
      vec[0][j].first = 1;
      vec[m - 1][j].second = 1;
      que.push({0, j});
      que.push({m - 1, j});
    }
    // 第一列和最后一列
    for (int i = 0; i < m; i++) {
      vec[i][0].first = 1;
      vec[i][n - 1].second = 1;
      que.push({i, 0});
      que.push({i, n - 1});
    }

    while (!que.empty()) {
      i = que.front().first;
      j = que.front().second;

      que.pop();
      // 可以到Ocean，那么高于它的邻居也可以到
      for (k = 0; k <= 3; k++) {
        neighbor_i = i + arr[k];
        neighbor_j = j + arr[k + 1];
        updated = false;
        if ((neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 &&
             neighbor_j < n) &&
            heights[neighbor_i][neighbor_j] >= heights[i][j]) {

          if (vec[i][j].first == 1 && vec[neighbor_i][neighbor_j].first != 1) {
            vec[neighbor_i][neighbor_j].first = 1;
            updated = true;
          }
          if (vec[i][j].second == 1 &&
              vec[neighbor_i][neighbor_j].second != 1) {
            vec[neighbor_i][neighbor_j].second = 1;
            updated = true;
          }

          // 邻居加入que，只有当邻居状态被改变时才加入
          if (updated) {
            que.push({neighbor_i, neighbor_j});
          }
        }
      }
    }

    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        if (vec[i][j].first == 1 && vec[i][j].second == 1) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
};

// #include <stdio.h>
// int main() {
//   Solution S;
//   vector<vector<int>> heights = {{1, 2, 2, 3, 5},
//                                  {3, 2, 3, 4, 4},
//                                  {2, 4, 5, 3, 1},
//                                  {6, 7, 1, 4, 5},
//                                  {5, 1, 1, 2, 4}};
//   vector<vector<int>> result = S.pacificAtlantic(heights);
//   for (auto &v : result) {
//     printf("[%d,%d]\t", v[0], v[1]);
//   }
//   printf("\n");
// }
