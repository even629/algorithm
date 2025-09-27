#include <numeric>
#include <vector>

using std::vector;

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    int n = nums.size();
    // 用 nums[0..top] 作为“栈”
    int top = 0;
    for (int i = 1; i < n; i++) {
      // std::gcd最大公约数 greatest common divisor
      // 如果栈顶 nums[top] 和当前 nums[i] 不是互质，就合并.
      // 一个数可能会和多个前面的数连续不互质。
      // 所以必须不断往回合并，直到和栈顶互质为止。
      while (top >= 0 and std::gcd(nums[top], nums[i]) > 1) {
        // std::lcm最小公倍数 least common multiple
        nums[i] = std::lcm(nums[top], nums[i]);
        // 弹出栈顶，继续和新的栈顶比较
        top--;
      }
      // 把合并后的结果压回栈顶
      nums[++top] = nums[i];
    }
    nums.resize(top + 1);
    return nums;
  }
};
