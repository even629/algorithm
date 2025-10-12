#include <vector>

using std::vector;

class Solution {
public:
  int maxArea(vector<int> &height) {
    // 从height最小的开始，离当前的端点最远且大于等于height的(左右都要寻找)
    int n, i, j;
    int max = -1;
    int curr_height;
    n = height.size();

    for (i = 0; i < n; i++) {
      curr_height = height[i];
      for (j = n - 1; j > i; j--) {
        if (height[j] >= curr_height) {
          max = std::max(max, curr_height * (j - i));
          break;
        }
      }
      for (j = 0; j < i; j++) {
        if (height[j] >= curr_height) {
          max = std::max(max, curr_height * (i - j));
          break;
        }
      }
    }
    return max;
  }
};
