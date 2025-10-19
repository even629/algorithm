#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
    public:
	int cel_div(int a, int b)
	{
		return (a + b - 1) / b;
	}
	int findSmallestInteger(vector<int> &nums, int value)
	{
		// 先将所有负数变为正数
		// 再将所有数变为除以value的余数

		int i;
		int n = nums.size();
		int group = INT_MAX;

		int res;

		unordered_map<int, int> umap;

		if (value == 1) {
			return n - 1;
		}

		for (i = 0; i < n; i++) {
			if (nums[i] < 0) {
				nums[i] += cel_div(-nums[i], value) * value;
			}
			nums[i] = nums[i] % value;
			umap[nums[i]]++;
		}

		for (i = 0; i < value; i++) {
			if (umap.count(i) == 0) {
				return i;
			}
		}

		for (auto &[num, count] : umap) {
			if (count < group) {
				group = count;
				res = num;
			} else if (count == group) {
				res = std::min(res, num);
			}
		}

		res += group * value - 1;

		return res;
	}
};

int main()
{
	vector<int> vec = { 3, 2, 3, 1, 0, 1, 4, 2, 3, 1, 4, 1, 3 };
	int value = 5;
	Solution s;
	s.findSmallestInteger(vec, value);
}
