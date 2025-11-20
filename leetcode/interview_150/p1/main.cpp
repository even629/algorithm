#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
    public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, vector<int> > num2index;
		int i, n = nums.size();
		for (int i = 0; i < n; i++) {
			if (!num2index.count(nums[i])) {
				num2index[nums[i]] = vector<int>();
			}
			num2index[nums[i]].push_back(i);
		}
		std::sort(nums.begin(), nums.end());
		int left = 0, right = n - 1;
		while (left < right) {
			if (nums[left] + nums[right] < target) {
				left++;
			} else if (nums[left] + nums[right] > target) {
				right--;
			} else {
				break;
			}
		}
		vector<int> res;
		if (nums[left] == nums[right]) {
			res = { num2index[nums[left]][0], num2index[nums[right]][1] };
		} else {
			res = { num2index[nums[left]].front(), num2index[nums[right]].front() };
		}
		return res;
	}
};
