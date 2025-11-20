#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	int findMinArrowShots(vector<vector<int> > &points)
	{
		std::sort(points.begin(), points.end(),
			  [](vector<int> &vec1, vector<int> &vec2) { return vec1[0] < vec2[0]; });
		vector<vector<int> > res_vec;

		vector<int> last;
		int curr_left, curr_right, last_left, last_right;
		for (vector<int> &point : points) {
			curr_left = point[0];
			curr_right = point[1];
			if (last.empty()) {
				res_vec.push_back({ curr_left, curr_right });
				last = res_vec.back();
			} else {
				last_left = last[0];
				last_right = last[1];
				if (curr_left > last_right) {
					res_vec.push_back({ curr_left, curr_right });
					last = res_vec.back();
				} else { // else if (curr_left <= last_right) {
					res_vec.pop_back();
					res_vec.push_back({ curr_left, std::min(curr_right, last_right) });
					last = res_vec.back();
				}
			}
		}

		return res_vec.size();
	}
};
