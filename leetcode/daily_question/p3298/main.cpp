#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
    public:
	vector<int> getSneakyNumbers(vector<int> &nums)
	{
		unordered_map<int, int> umap;
		vector<int> res;
		int i, n = nums.size();
		for (i = 0; i < n; i++) {
			umap[nums[i]]++;
			if (umap[nums[i]] == 2) {
				res.push_back(nums[i]);
			}
			if (res.size() == 2) {
				break;
			}
		}
		return res;
	}
};
