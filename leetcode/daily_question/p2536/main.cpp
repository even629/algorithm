#include <vector>
using std::vector;

class Solution {
    public:
	vector<vector<int> > rangeAddQueries(int n, vector<vector<int> > &queries)
	{
		vector<vector<int> > mat(n, vector<int>(n, 0));
		// 差分矩阵
		vector<vector<int> > diff(n + 1, vector<int>(n + 1, 0));
		int row1, col1, row2, col2;
		int x1, x2, x3;
		for (const auto &query : queries) {
			row1 = query[0];
			col1 = query[1];
			row2 = query[2];
			col2 = query[3];
			diff[row1][col1] += 1;
			diff[row2 + 1][col1] -= 1;
			diff[row1][col2 + 1] -= 1;
			diff[row2 + 1][col2 + 1] += 1;
		}

		// 前缀和+差分
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				x1 = i >= 1 ? mat[i - 1][j] : 0;
				x2 = j >= 1 ? mat[i][j - 1] : 0;
				x3 = i >= 1 && j >= 1 ? mat[i - 1][j - 1] : 0;
				mat[i][j] = diff[i][j] + x1 + x2 - x3;
			}
		}
		return mat;
	}
};
