#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval)
	{
		vector<vector<int> > res;
		int i, n = intervals.size();
		int curr_left, curr_right, new_left = newInterval[0], new_right = newInterval[1];
		for (i = 0; i < n; i++) {
			curr_left = intervals[i][0];
			curr_right = intervals[i][1];
			if (curr_right < new_left) {
				res.push_back({ curr_left, curr_right });
			} else {
				break;
			}
		}
		// 合并区间
		for (; i < n; i++) {
			curr_left = intervals[i][0];
			curr_right = intervals[i][1];
			if (curr_left <= new_right) {
				new_left = std::min(new_left, curr_left);
				new_right = std::max(new_right, curr_right);

			} else {
				break;
			}
		}
		res.push_back({ new_left, new_right });

		for (; i < n; i++) {
			curr_left = intervals[i][0];
			curr_right = intervals[i][1];
			res.push_back({ curr_left, curr_right });
		}
		return res;
	}
};
