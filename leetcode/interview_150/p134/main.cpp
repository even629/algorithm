#include <vector>
using std::vector;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int start = -1;
    int curr_gas;
    int i, idx;
    for (int i = 0; i < n; i++) {
      // 到达i前至少有多少油才能去下一个
      if (gas[i] - cost[i] >= 0) {
        start = i;
        break;
      }
    }
    if (start == -1) {
      return -1;
    }

    while (start < n) {
      curr_gas = 0;
      i = 0;
      // 走一圈
      for (i = 0; i < n; i++) {
        idx = (start + i) % n;
        curr_gas += gas[idx] - cost[idx];
        if (curr_gas < 0) {      // 路线失败
          start = start + i + 1; // 直接跳过失败区间
          // 成功绕一圈
          break;
        }
      }
      if (i == n)
        return start;
    }

    return -1;
  }
};

#include <stdio.h>
int main() {

  Solution S;
  vector<int> gas = {5, 1, 2, 3, 4};
  vector<int> cost = {4, 4, 1, 5, 1};
  printf("%d\n", S.canCompleteCircuit(gas, cost));
}
