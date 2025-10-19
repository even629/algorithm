#include <vector>
using std::vector;

class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int i;
    int a = 0, b = k;
    int n = nums.size();

  loop:
    while (b + k - 1 < n) {
      for (i = 1; i < k; i++) {
        if (nums[a + i] > nums[a + i - 1] && nums[b + i] > nums[b + i - 1]) {
          continue;
        } else {
          a += i;
          b = a + k;
          goto loop;
        }
      }
      return true;
    }
    return false;
  }
};

#include <stdio.h>
int main() {
  Solution s;
  vector<int> vec = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
  printf("%d\n", s.hasIncreasingSubarrays(vec, 3));
  vec = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
  printf("%d\n", s.hasIncreasingSubarrays(vec, 5));
}
