#include <algorithm>
#include <vector>

using std::vector;
class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    int n = nums.size();

    int i, j, k;
    int length;

    std::sort(nums.begin(), nums.end());
    if (n < 3) {
      return 0;
    }
    // 固定最大边nums[k]，双指针找次大边nums[j]和最小边nums[i]
    for (k = n - 1; k >= 2; k--) {
      length = nums[k - 1] + nums[k - 2];
      if (nums[k] < length) {
        return length + nums[k];
      }
    }
    return 0;
  }
};
