#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int n = prices.size();
    int max_profit = 0;
    int min_price = INT_MAX;
    for (int i = 0; i < n; i++) {
      max_profit = std::max(prices[i] - min_price, max_profit);
      min_price = std::min(prices[i], min_price);
    }
    return max_profit;
  }
};

#include <stdio.h>
int main() {
  Solution s;
  vector<int> vec = {3, 3, 5, 0, 0, 3, 1, 4};
  printf("%d\n", s.maxProfit(vec));
}
