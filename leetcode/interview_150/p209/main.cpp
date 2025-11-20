#include <vector>
#include <climits>
#include <algorithm>
using std::vector;

class Solution {
    public:
	int minSubArrayLen(int target, vector<int> &nums)
	{
		int n = nums.size();
		int left = 0;
		int curr_sum = 0;
		int res = INT_MAX;

		for (int right = 0; right < n; ++right) {
			curr_sum += nums[right];

			// 当窗口内的和 >= target 时，尝试收缩左边界
			while (curr_sum >= target) {
				res = std::min(res, right - left + 1);
				curr_sum -= nums[left];
				left++;
			}
		}

		return (res == INT_MAX ? 0 : res);
	}
};
