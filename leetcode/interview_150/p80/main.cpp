/* nums是有序数组
 * 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次，
 * 返回删除后数组的新长度。 不要使用额外的数组空间，你必须在 原地 修改输入数组
 * 并在使用 O(1) 额外空间的条件下完成
 */
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i, n;
    n = nums.size();
    i = 0;

    while (i < nums.size()) {
      if (i >= 2 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
        nums.erase(nums.begin() + i);
      } else {
        i++;
      }
    }

    return nums.size();
  }
};
