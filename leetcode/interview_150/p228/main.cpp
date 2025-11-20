#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public:
	vector<string> summaryRanges(vector<int> &nums)
	{
		vector<string> res;
		int i, n = nums.size();

		if (n == 0) {
			return res;
		}
		int start = nums[0];
		for (i = 1; i < n; i++) {
			if (nums[i] != nums[i - 1] + 1) {
				// start..i-1
				string curr;

				curr.append(std::to_string(start));
				if (nums[i - 1] > start) {
					curr.append("->");
					curr.append(std::to_string(nums[i - 1]));
				}
				res.push_back(curr);
				start = nums[i];
			}
		}

		string curr;
		curr.append(std::to_string(start));
		if (nums[n - 1] > start) {
			curr.append("->");
			curr.append(std::to_string(nums[n - 1]));
		}
		res.push_back(curr);

		return res;
	}
};

int main()
{
	vector<int> nums = { 0, 1, 2, 4, 5, 7 };
	Solution S;
	S.summaryRanges(nums);
}
