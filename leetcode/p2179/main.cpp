#include <stdio.h>
#include <vector>
using std::vector;

bool notCoprime(int x, int y) {
  int t;
  while (y != 0) {
    t = y;
    y = x % y;
    x = t;
  }
  return x != 1; // GCD != 1 就不是互质
}

int gcd_fn(int x, int y) {
  while (y != 0) {
    int t = y;
    y = x % y;
    x = t;
  }
  return x;
}

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    // 滑动窗口，从左到右，从右到左，直到没有可以合并的才停止
  }
};

int main() {
  Solution s;
  vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
  s.replaceNonCoprimes(nums);
  for (auto it = nums.begin(); it != nums.end(); it++) {
    printf("%d ", *it);
  }
  return 0;
}
