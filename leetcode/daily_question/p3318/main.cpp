#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;

class Solution {
	// [start, end)
	int get_x_sum(vector<int> &nums, int start, int end, int x)
	{
		unordered_map<int, int> mp;
		// 默认大顶堆, {val, key}
		priority_queue<pair<int, int>, vector<pair<int, int> > >
			max_heap;
		int n = start - end;
		int i, sum = 0;
		for (i = start; i < end; i++) {
			mp[nums[i]]++;
			sum += nums[i];
		}
		if (mp.size() < x) {
			return sum;
		}

		for (auto [num, count] : mp) {
			max_heap.push({ count, num });
		}
		sum = 0;
		for (i = 0; i < x; i++) {
			auto [count, num] = max_heap.top();
			sum += count * num;
			max_heap.pop();
		}
		return sum;
	}

    public:
	vector<int> findXSum(vector<int> &nums, int k, int x)
	{
		int i, n = nums.size();
		vector<int> answer(n - k + 1);

		for (i = 0; i < n - k + 1; i++) {
			answer[i] = get_x_sum(nums, i, i + k, x);
		}
		return answer;
	}
};
