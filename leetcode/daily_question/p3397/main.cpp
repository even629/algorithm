#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    public:
	int maxDistinctElements(vector<int> &nums, int k)
	{
		int i, j;
		int n = nums.size();
		int res = 1;
		int last_val;
		int offset;

		std::sort(nums.begin(), nums.end());

		last_val = nums[i] - k;

		for (i = 1; i < n; i++) {
			offset = nums[i] - nums[i - 1];
			if (offset == 0 && last_val != nums[i - 1] + k) {
				last_val = last_val + 1;
				res++;
			} else if (offset == 0 && last_val == nums[i - 1] + k) {
				continue;
			} else if (offset > 2 * k) {
				last_val = nums[i] - k;
				res++;

			} else { // 0 < offset <= 2*k
				if (nums[i] - k > last_val) {
					last_val = nums[i] - k;
					res++;

				} else {
					last_val = last_val + 1;
					res++;
				}
			}
		}

		return res;
	}
};
int main()
{
	Solution s;
	vector<int> vec = { 1, 2, 2, 3, 3, 4 };
	s.maxDistinctElements(vec, 2);
}
