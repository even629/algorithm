#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
    public:
	int minCost(string colors, vector<int> &neededTime)
	{
		int i = 0, j=1, n = colors.size();
		int res = 0;
		int max_time;
		int total;
		while (j < n) {
			j = i + 1;
			total = neededTime[i];
			max_time = neededTime[i];
			while (colors[i] == colors[j]) {
				max_time = std::max(neededTime[j], max_time);
				total += neededTime[j];
				j++;
			}
			if (total == neededTime[i]) {
			    i++;
			} else {
				res += total - max_time;
				i = j;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	string colors = "abaac";
	vector<int> neededTime = { 1,2,3,4,5 };
	s.minCost(colors, neededTime);
}
