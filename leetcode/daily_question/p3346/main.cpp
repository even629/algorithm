#include <vector>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;

using std::vector;

class Solution {
    public:
	int maxFrequency(vector<int> &nums, int k, int numOperations)
	{
		int i, j;

		int operation;
		int lconsume, rconsume;
		int min, max;
		int n = nums.size();
		//unordered_map<int, int> umap;
		// for (i = 0; i < n; i++) {
		// 	umap[nums[i]]++;
		// }

		// 排序
		std::sort(nums.begin(), nums.end());
		// 去重
		//nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
		n = nums.size();

		// 枚举每一位，从这一位的左，右枚举
		for (i = 0; i < n; i++) {
			operation = numOperations;
			for (j = 1; j < n; j++) {
				if (i - j >= 0 && i + j < n) { //左右都存在

				} else if (i - j < 0 &&
					   i + j < n) { // 只有右边存在

				} else if (i - j >= 0 &&
					   i + j >= n) { //只有左边存在
				}
			}
		}
	}
};

int main()
{
	vector<int> nums = { 88, 53 };
	Solution S;
	S.maxFrequency(nums, 27, 2);
}
