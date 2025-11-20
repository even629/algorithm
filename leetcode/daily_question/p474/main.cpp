#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
    public:
	int findMaxForm(vector<string> &strs, int m, int n)
	{
		// 0-1背包问题
		int i, j;
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
		int zero_count, one_count;

		for (auto &s : strs) {
			zero_count = std::count(s.begin(), s.end(), '0');
			one_count = s.size() - zero_count;

			// 关键：反向遍历，防止重复使用
			for (i = m; i >= zero_count; --i) {
				for (j = n; j >= one_count; --j) {
					dp[i][j] = std::max(dp[i][j], dp[i - zero_count][j - one_count] + 1);
				}
			}
		}
		return dp[m][n];
	}
};
