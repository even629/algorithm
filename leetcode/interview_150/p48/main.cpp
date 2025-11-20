#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	void rotate(vector<vector<int> > &matrix)
	{
		// 先沿对角线翻转
		int i, j, n = matrix.size();
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
		// 再逐行逆序
		for (i = 0; i < n; i++) {
			std::reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};
