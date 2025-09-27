
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  // 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数
  // 1 <= nums.length <= 1000
  // 0 <= nums[i] <= 1000
  int triangleNumber(vector<int> &nums) {
    // 三角形两边之和大于第三边

    if (nums.size() < 3) {
      return 0;
    }
    vector<int> vec(nums);
    int n;
    int i, j, k;
    int res = 0;

    // 排序
    std::sort(nums.begin(), nums.end());
    // 去重,去重前需要先排序
    // vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    n = vec.size();
    // 先固定最大边,k为三角形中最大的边,其次是j,i是最小的
    for (k = n - 1; k >= 2; k--) {
      i = 0;
      j = k - 1;
      while (i < j) {
        if (nums[i] + nums[j] > nums[k]) {
          // 因为j是从k-1向前遍历,i从0向后遍历
          // 所以如果 nums[i] + nums[j] > nums[k]
          // 所有 [i,j-1] 都和 j, k 可以组成三角形
          res += (j - i);
          --j;
        } else {
          // 不满足三角形构成条件说明i太小了
          // 令i++,直到i==j时退出循环
          // 因为此时k和j固定,任何一个i都无法满足三角形构成条件
          // 说明k太大了,令k--
          i++;
        }
      }
    }

    return res;
  }
};
