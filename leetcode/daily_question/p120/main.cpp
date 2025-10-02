#include <climits>
#include <vector>

using std::vector;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    int min = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] 表示从第i+1行第j+1列出来的最小值
    // 当j!=0 && j!=i时
    // dp[i][j] = min {dp[i-1][j-1] + dp[i-1][j]} + triangle[i][j]
    // 当j==0 时 dp[i][j] = dp[i-1][0] + triangle[i][j]
    // 当j==i 时 dp[i][j] = dp[i-1][j-1] + triangle[i][j]
    dp[0][0] = triangle[0][0];
    // 从第二行开始，也就是i==1
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][0] + triangle[i][j];
        } else if (j == i) {
          dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        } else {
          dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (dp[n - 1][j] < min) {
        min = dp[n - 1][j];
      }
    }
    return min;
  }
};
