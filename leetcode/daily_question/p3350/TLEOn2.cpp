#include <vector>
using std::vector;

class Solution {
public:
  // 降低复杂度的关键思路
  // 我们定义一个数组 inc[i]：
  // inc[i] = 以 nums[i] 结尾的最长递增子数组的长度。
  int maxIncreasingSubarrays(vector<int> &nums) {
    int n = nums.size();
    int i;
    // n从2开始
    int k = n / 2;
    int a, b;
    vector<int> inc(n, 1);
    for (i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        inc[i] = inc[i - 1] + 1;
      }
    }

    while (k > 0) {
      a = 0;
      b = a + k;
      while (b + k - 1 < n) {
        if (inc[a + k - 1] >= k && inc[b + k - 1] >= k) {
          return k;
        } else {
          a++;
          b = a + k;
        }
      }
      k--;
      if (k == 1) {
        return 1;
      }
    }
    return 1;
  }
};
