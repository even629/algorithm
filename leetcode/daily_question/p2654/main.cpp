#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using std::vector;

class Solution {
    public:
	int minOperations(vector<int> &nums)
	{
		int n = nums.size();
		int cnt1 = 0;
		for (int x : nums) {
			if (x == 1) {
				cnt1++;
			}
		}

		// 情况1：数组中已经有1
		if (cnt1 > 0) {
			return n - cnt1;
		}

		// 情况2：没有1，找最短gcd为1的子数组
		// 我们要找出 最短子数组 gcd = 1 的长度为 len。
		// 只要能在那段中通过操作造出一个 1，然后再传播到全数组需要 n - 1 次操作。
		// 答案 = len - 1 + (n - 1)。
		int ans = INT_MAX;
		int g;
		for (int i = 0; i < n; i++) {
			g = nums[i];
			for (int j = i + 1; j < n; j++) {
				g = std::gcd(g, nums[j]);
				if (g == 1) {
					// j-i+1为gcd为1的子数组长度
					ans = std::min(ans, j - i + 1);
					break;
				}
			}
		}

		if (ans == INT_MAX) {
			return -1; // 不可能造出1
		}
		return (ans - 1) + (n - 1); // 造出一个1，再扩散成全1
	}
};
