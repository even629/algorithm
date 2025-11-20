#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;

class Solution {
    public:
	int longestConsecutive(vector<int> &nums)
	{
		unordered_set<int> uset;
		for (int &num : nums) {
			uset.insert(num);
		}
		int longest = 0, curr = 0;
		for (auto &num : uset) {
			if (!uset.count(num - 1)) {
				curr = 1;
				while (uset.count(num + curr)) {
					curr++;
				}
				longest = std::max(curr, longest);
			}
		}
		return longest;
	}
};
