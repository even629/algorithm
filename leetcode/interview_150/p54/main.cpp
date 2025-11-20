#include <vector>
using std::vector;

class Solution {
    public:
	bool spiral_edge(vector<vector<int> > &matrix, vector<int> &res, int curr_m, int curr_n, int start_i,
			 int start_j)
	{
		int i = start_i, j = start_j;
		int cnt = 0, total = curr_m * curr_n;
		if (curr_m <= 0 || curr_n <= 0) {
			return false;
		}
		// 从(start_i,start_j)开始,长度为curr_m,curr_n
		for (i = start_i, j = start_j; j < start_j + curr_n; j++) {
			res.push_back(matrix[i][j]);
			cnt++;
		}
		if (cnt == total) {
			return true;
		}
		for (i = start_i + 1, j = start_j + curr_n - 1; i < start_i + curr_m - 1; i++) {
			res.push_back(matrix[i][j]);
			cnt++;
		}
		if (cnt == total) {
			return true;
		}
		for (i = start_i + curr_m - 1, j = start_j + curr_n - 1; j >= start_j; j--) {
			res.push_back(matrix[i][j]);
			cnt++;
		}
		if (cnt == total) {
			return true;
		}
		for (i = start_i + curr_m - 2, j = start_j; i > start_i; i--) {
			res.push_back(matrix[i][j]);
			cnt++;
		}
		return true;
	}
	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> res;
		int curr_m = m, curr_n = n;
		int start_i = 0, start_j = 0;
		while (spiral_edge(matrix, res, curr_m, curr_n, start_i, start_j)) {
			curr_m -= 2;
			curr_n -= 2;
			start_i += 1;
			start_j += 1;
		}

		return res;
	}
};
int main()
{
	vector<vector<int> > matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	Solution S;
	S.spiralOrder(matrix);
}
