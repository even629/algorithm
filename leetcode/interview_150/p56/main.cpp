#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	vector<vector<int> > merge(vector<vector<int> > &intervals)
	{
		std::sort(intervals.begin(), intervals.end(),
			  [](vector<int> &vec1, vector<int> &vec2) { return vec1[0] < vec2[0]; });
		vector<vector<int> > res;
		vector<int> last;
		int left, right, last_left, last_right;
		for (vector<int> &interval : intervals) {
			left = interval[0];
			right = interval[1];
			if (last.empty()) {
				res.push_back({ left, right });
				last = res.back();
			} else {
				last_left = last[0];
				last_right = last[1];
				if (left <= last_right && right > last_right) {
					res.pop_back();
					res.push_back({ last_left, right });
					last = res.back();
				} else if (left <= last_right && right <= last_right) {
					continue;
				} else if (left > last_right) {
					res.push_back({ left, right });
					last = res.back();
				}
			}
		}
		return res;
	}
};
