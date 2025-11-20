#include <vector>
#include <climits>
using std::vector;

class Solution {
    public:
	void ops(vector<int> &nums, int start, int end)
	{
		int i;
		int min = INT_MAX;
		for (i = start; i < end; i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
		}
		for (i = start; i < end; i++) {
			if (nums[i] == min) {
				nums[i] = 0;
			}
		}
	}
	int minOperations(vector<int> &nums)
	{
		// 滑动窗口
		int left = 0, right = 0;
		int n = nums.size();
		int res = 0;
		while (left < n) {
			while (left < n && nums[left] == 0) {
				left++;
			}
			right = left;
			while (right < n && nums[right] > 0) {
				right++;
			}
			// [left, right)
			if (left == right && left == n) {
				break;
			}
			ops(nums, left, right);
			res++;
			//left = right;
		}
		return res;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 1, 2, 1, 2 };
	Solution S;
	S.minOperations(nums);
}
