#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;

class Solution {
    public:
	vector<vector<int> > threeSum(vector<int> &nums)
	{
		// nums[i] + nums[j] + nums[k] == 0

		std::sort(nums.begin(), nums.end());

		vector<vector<int> > res;

		int n = nums.size();
		int i, j, k, val;

		queue<pair<int, int> > que;

		que.push({ 0, n - 1 });
		while (!que.empty()) {
			i = que.front().first;
			k = que.front().second;

			val = nums[i] + nums[k];
			que.pop();

			if (i + 1 < k - 1 && val + nums[k - 1] < 0) { //最大值还小于0
				que.push({ i + 1, k });
			} else if (k - 1 > i + 1 && val + nums[i + 1] > 0) { //最小值还大于0
				que.push({ i, k - 1 });
			} else {
				for (j = i + 1; j < k; j++) {
					if (val + nums[j] == 0) {
						res.push_back({ nums[i], nums[j], nums[k] });
						break;
					}
				}
				// i++或j--都要尝试
				if (i + 1 < k + 1) {
					que.push({ i + 1, k });
				}
				if (k - 1 > i + 1) {
					que.push({ i, k - 1 });
				}
			}
		}
		std::sort(res.begin(), res.end());
		res.erase(std::unique(res.begin(), res.end()), res.end());
		return res;
	}
};
