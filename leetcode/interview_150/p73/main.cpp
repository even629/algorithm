#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
    public:
	void setZeroes(vector<vector<int> > &matrix)
	{
		unordered_set<int> iuset;
		unordered_set<int> juset;
		int i, j, m = matrix.size(), n = matrix[0].size();
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					iuset.insert(i);
					juset.insert(j);
				}
			}
		}
		for (i = 0; i < m; i++) {
			if (iuset.count(i)) { // 这一行都为0
				std::fill(matrix[i].begin(), matrix[i].end(), 0);
				continue;
			}
			for (j = 0; j < n; j++) {
				if (juset.count(j)) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};
