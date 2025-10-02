#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using std::pair;
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // dp[i][0] 第i天最大利润并且不持有股票
    // dp[i][1] 第i天最大利润且持有股票
    int n;
    n = prices.size();
    vector<pair<int, int>> dp(n, {0, 0});
    // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
    // dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1])
    dp[0].first = 0;
    dp[0].second = -prices[0];

    for (int i = 1; i < n; i++) {
      dp[i].first = std::max(dp[i - 1].first, dp[i - 1].second + prices[i]);
      dp[i].second = std::max(dp[i - 1].first - prices[i], dp[i - 1].second);
    }
    return dp[n - 1].first;
  }
};
