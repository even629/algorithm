#include <vector>
using std::vector;

class Solution {
    public:
	bool kLengthApart(vector<int> &nums, int k)
	{ //只需要判断相邻的是否至少相隔k个元素即可
		int last = -1, i, n = nums.size();
		// 找到第一个1
		for (i = 0; i < n; i++) {
			if (nums[i] == 1) {
				last = i;
				break;
			}
		}

		if (last == -1) {
			return true;
		}
		for (i = last + 1; i < n; i++) {
			if (nums[i] == 1) {
				if (i - last - 1 < k) {
					return false;
				} else {
					last = i;
				}
			}
		}
		return true;
	}
};
