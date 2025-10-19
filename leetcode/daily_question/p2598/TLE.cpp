#include <vector>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::vector;

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
		int top_value;
		int last_value;
		int count = 0;
		priority_queue<int, vector<int>, std::greater<int> > min_heap;
		if (value == 1) {
			return n - 1;
		}

		for (i = 0; i < n; i++) {
			if (nums[i] < 0) {
				nums[i] += cel_div(-nums[i], value) * value;
			}
			nums[i] = nums[i] % value;
			min_heap.push(nums[i]);
		}

		last_value = -1;

		while (!min_heap.empty()) {
			top_value = min_heap.top();
			if (top_value == last_value) {
				min_heap.pop();
				min_heap.push(top_value + value);
				continue;
			}
			if (top_value != last_value + 1) {
				break;
			} else {
				last_value = top_value;
				min_heap.pop();
			}
		}

		return last_value + 1;
	}
};

int main()
{
	vector<int> vec = { 3, 0, 3, 2, 4, 2, 1, 1, 0, 4 };
	int value = 5;
	Solution s;
	s.findSmallestInteger(vec, value);
}
