#include <algorithm>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
  long long maximumTotalDamage(vector<int> &power) {
    // 令 f(i) 表示从第 0 到 i 种咒语中选择，并且最后选择第 i 种咒语的最大总伤害
    // f(i) = max(f(j), j< i && power[j] < power[i]-2) + power[i] * mp[power[i]]
    int i, j, n;
    long long max = 0, ans = 0;
    unordered_map<long, long> count;

    for (int p : power) {
      count[p]++;
    }

    // 去重
    power.erase(std::unique(power.begin(), power.end()), power.end());
    // 排序
    std::sort(power.begin(), power.end());

    n = power.size();

    vector<long long> f(n, 0);
    f[0] = power[0] * count[power[0]];

    for (i = 1, j = 0; i < n; i++) {
      while (j < i && power[j] < power[i] - 2) {
        max = std::max(max, f[j]);
        j++;
      }
      f[i] = max + power[i] * count[power[i]];
    }

    ans = *std::max_element(f.begin(), f.end());

    return ans;
  }
};
