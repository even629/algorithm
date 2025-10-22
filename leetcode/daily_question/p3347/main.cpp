#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
    public:
	int maxFrequency(vector<int> &nums, int k, int numOperations)
	{
		int n = nums.size();
		int i;
		int range_size;
		int res = 0;
		unordered_map<int, int> umap;
		for (i = 0; i < n; i++) {
			umap[nums[i]]++;
		}
		std::sort(nums.begin(), nums.end());

		n = nums.size();
		// 0 <= numOperations <= nums.length
		for (i = 0; i < n; i++) {
			for (int val : { nums[i] - k, nums[i], nums[i] + k }) {
				// 要枚举的值不在范围内
				if (val < nums.front() || val > nums.back()) {
					// 如果val比nums最小值还小，没有意义，因为任何一个值能通过操作变成这个val，那么肯定也可以变成nums的最小值，那么为什么不用最小值作为目标众数呢？
					continue;
				}
				// range {x in nums[i] && x in {val-k..val+k}}
				range_size =
					std::upper_bound(nums.begin(),
							 nums.end(), val + k) -
					std::lower_bound(nums.begin(),
							 nums.end(), val - k);

				// 最终能把某个值变成出现次数最多的频率 = 原来这个值的出现次数 +
				// 通过操作可以变成这个值的次数,但不能超过窗口内可转换到的数量
				res = std::max(
					res, std::min(numOperations + umap[val],
						      range_size));
			}
		}
		return res;
	}
};

int main()
{
	vector<int> nums = { 999999997, 999999999, 999999999 };
	Solution S;
	int k = 999999999;
	int numOperations = 2;
	S.maxFrequency(nums, k, numOperations);
}
