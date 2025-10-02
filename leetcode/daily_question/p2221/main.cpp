#include <vector>
using std::vector;

class Solution {
public:
  int triangularSum(vector<int> &nums) {
    int i;
    int bound;
    int n = nums.size();

    for (int k = 0; k < n; k++) {
      i = 0;
      bound = n - k;
      while (i < bound - 1) {
        nums[i] = (nums[i] + nums[i + 1]) % 10;
        i++;
      }
    }
    return nums[0];
  }
};
