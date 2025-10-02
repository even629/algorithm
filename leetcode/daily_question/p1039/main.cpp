#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  // dp[i][j] 第i个顶点到第j个顶点的凸多边形的最小三角形剖分分数
  // k为i~j内任意一个顶点不包括i和j，那么dp[i][j] =min k{ dp[i][k] + dp[k][j]  +
  // values[i] *values[j] *values[k]}
  int minScoreTriangulation(vector<int> &values) {
    int vertex; // i~j共有多少个顶点
    int i, j, k;
    int n;

    n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (vertex = 2; vertex < n; vertex++) {
      for (i = 0; i + vertex < n; i++) {
        j = i + vertex;
        dp[i][j] = INT_MAX;
        for (k = i + 1; k < j; k++) {
          dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] +
                                            values[i] * values[j] * values[k]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
