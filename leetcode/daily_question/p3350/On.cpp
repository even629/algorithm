// #include <limits.h>
#include <vector>
using std::vector;

class Solution {
public:
  // 遍历数组，计算所有连续递增段的长度。
  int maxIncreasingSubarrays(vector<int> &nums) {
    int n = nums.size();
    int i;

    int curr_len = 1;
    // prev_len取0，否则第一次判断时会更新max，即使前面没有数据段
    int prev_len = 0;
    int max_val = 0;

    int len_max = 0;
    if (n <= 1) {
      return 0;
    }

    for (i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        curr_len++;
      } else {
        max_val = std::max(max_val, std::min(curr_len, prev_len));
        len_max = std::max(curr_len, len_max);
        prev_len = curr_len;
        curr_len = 1;
      }
    }
    len_max = std::max(len_max, curr_len);

    max_val = std::max(max_val, std::min(curr_len, prev_len));
    max_val = std::max(len_max / 2, max_val);

    return max_val;
  }
};
