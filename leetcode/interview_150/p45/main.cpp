#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  int jump(vector<int> &nums) {
    // dp[i]表示到达i的最小跳跃次数,-1表示不可达
    // 对于 0<=j <i
    // if(nums[j] + j >= i ) dp[i] = dp[j] +1;
    // 如果不存在这样的j,dp[i] = -1;
    int n;
    int min;
    n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
      min = INT_MAX;
      for (int j = 0; j < i; j++) {
        if (nums[j] + j >= i && dp[j] != -1 && dp[j] + 1 < min) {
          min = dp[j] + 1;
        }
      }
      if (min != INT_MAX) {
        dp[i] = min;
      } else {
        dp[i] = -1;
      }
    }
    return dp[n - 1];
  }
};
