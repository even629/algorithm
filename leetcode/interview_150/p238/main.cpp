#include <vector>
using std::vector;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int i;
    // n>=2
    int n = nums.size();

    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> result(n);
    prefix[0] = 1;
    prefix[1] = nums[0];
    for (i = 2; i < n; i++) {
      prefix[i] = nums[i - 1] * prefix[i - 1];
    }
    suffix[n - 1] = 1;
    suffix[n - 2] = nums[n - 1];
    for (i = n - 3; i >= 0; i--) {
      suffix[i] = nums[i + 1] * suffix[i + 1];
    }
    for (i = 0; i < n; i++) {
      result[i] = prefix[i] * suffix[i];
    }
    return result;
  }
};
