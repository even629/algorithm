#include <vector>

using std::vector;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n;
    int tmp;
    int pos;

    n = nums.size();
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
      pos = (i + k) % n;
      vec[pos] = nums[i];
    }
    nums = std::move(vec);
  }
};
