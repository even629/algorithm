#include <limits.h>
#include <string.h>
#include <vector>
using std::vector;

class Solution {
public:
  // 1 <= nums[i] <= 100
  int maxFrequencyElements(vector<int> &nums) {
    int n = nums.size();
    int max = INT_MIN;
    int res = 0;
    int array[101];
    memset(array, 0, 101 * sizeof(int));
    for (int i = 0; i < n; i++) {
      array[nums[i]]++;
    }

    for (int i = 1; i < 101; i++) {
      if (array[i] > max) {
        max = array[i];
      }
    }
    for (int i = 1; i < 101; i++) {
      if (array[i] == max) {
        res += array[i];
      }
    }
    return res;
  }
};
