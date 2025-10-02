#include <vector>
using std::vector;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int i, k;

    k = nums.size() - 1;
    i = 0;

    while (i <= k) {
      if (nums[i] == val) {
        std::swap(nums[i], nums[k]);
        k--;

      } else {
        i++;
      }
    }

    return k + 1;
  }
};
