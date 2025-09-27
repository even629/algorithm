#include <vector>
using std::vector;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> vec;
    int i = 0, j = 0;
    while (1) {
      if (i < m && j < n) {
        if (nums1[i] <= nums2[j])
          vec.push_back(nums1[i++]);
        else
          vec.push_back(nums2[j++]);
      } else if (i < m && j >= n) {
        vec.push_back(nums1[i++]);
      } else if (i >= m && j < n) {
        vec.push_back(nums2[j++]);
      } else {
        break;
      }
    }
    nums1 = std::move(vec);
  }
};
