#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	vector<vector<int> > threeSum(vector<int> &nums)
	{
		int n = nums.size();
		int i, j, k;
		int left_val, right_val;
		vector<vector<int> > res;
		std::sort(nums.begin(), nums.end());
		// 固定最小的那个数
		for (i = 0; i < n - 2; i++) {
			j = i + 1;
			k = n - 1;
			if (i > 0 && nums[i] == nums[i - 1]) { // 跳过重复的最小元素
				// 因为前一个相同元素的j,k选择区间包含了当前相同元素的这个区间
				continue;
			}
			if (nums[i] > 0) { // 最小的数必定小于0
				continue;
			}
			while (j < k) {
				if (nums[i] + nums[k] + nums[j] > 0) {
					k--;
				} else if (nums[i] + nums[k] + nums[j] < 0) {
					j++;
				} else {
					res.push_back({ nums[i], nums[j], nums[k] });
					// 跳过重复元素
					left_val = nums[j];
					right_val = nums[k];
					while (j < k && nums[j] == left_val) {
						j++;
					}
					while (k < j && nums[k] == right_val) {
						k--;
					}
				}
			}
		}
		return res;
	}
};
