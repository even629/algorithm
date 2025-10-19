#include <vector>
using std::vector;

class Solution {
public:
  int maxIncreasingSubarrays(vector<int> &nums) {
    int n = nums.size();
    // n从2开始
    int k = n / 2;
    int a, b, i;
    int flag = true;

    while (k > 0) {
      a = 0;     // 0..k-1
      b = a + k; // a+k.. b+k-1
      while (b + k - 1 < n) {
        flag = true;
        for (i = 1; i < k; i++) {
          if (nums[a + i] > nums[a + i - 1] && nums[b + i] > nums[b + i - 1]) {
            continue;
          } else {
            a++;
            b = a + k;
            flag = false;
            break;
          }
        }
        if (flag) {
          return k;
        }
      }
      k--;
    }
    return 0;
  }
};

#include <stdio.h>
int main() {
  vector<int> vec = {19, -14, 0, 9};
  Solution s;
  printf("%d\n", s.maxIncreasingSubarrays(vec));
}
