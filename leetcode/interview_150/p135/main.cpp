#include <numeric>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	int candy(vector<int> &ratings)
	{
		int i, n = ratings.size();

		vector<int> candies(n, 1);
		// left to right
		for (i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1]) {
				candies[i] = candies[i - 1] + 1;
			}
		}
		// right to left
		for (i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				candies[i] = std::max(candies[i + 1] + 1,
						      candies[i]);
			}
		}

		return std::accumulate(candies.begin(), candies.end(), 0);
	}
};
