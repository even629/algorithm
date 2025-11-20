#include <cstdlib>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
    public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		unordered_map<int, vector<int> > num2index;
		int i, j, n = nums.size();
		for (i = 0; i < n; i++) {
			num2index[nums[i]].push_back(i);
		}
		for (auto &[_, index_vec] : num2index) {
			if (index_vec.size() > 1) {
				n = index_vec.size();
				for (i = 0; i < n; i++) {
					for (j = i + 1; j < n; j++) {
						if (std::abs(index_vec[i] - index_vec[j]) <= k) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
};
