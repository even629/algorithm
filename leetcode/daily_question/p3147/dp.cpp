#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
  int maximumEnergy(vector<int> &energy, int k) {
    // 设所求，由于最大能量与以前状态有关，判断可以用动态规划解决
    // 设dp[i]为到达第i个魔法师所能获得的最大能量
    // dp[i] = max(energy[i],dp[i-k]+energy[i]);
    // 边界条件：dp[i] = energy[i];       i<k
    // 倒数k个dp取max。

    int n = energy.size();
    int res;
    vector<int> dp(n);

    std::copy(energy.begin(), energy.end(), dp.begin());

    for (int i = k; i < n; i++) {
      dp[i] = std::max(energy[i], dp[i - k] + energy[i]);
    }

    res = *std::max_element(dp.end() - k, dp.end());

    return res;
  }
};
