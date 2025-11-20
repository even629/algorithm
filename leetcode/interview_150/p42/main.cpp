#include <vector>
#include <algorithm>
using std::vector;

class Solution {
    public:
	int trap(vector<int> &height)
	{
		int n = height.size();
		int left_boundary = 0, right_boundary = n - 1;
		int lower;
		int rain = 0;
		while (left_boundary < right_boundary) {
			lower = std::min(height[left_boundary],
					 height[right_boundary]);
			// 向边界最低的地方灌水
			if (height[left_boundary] < height[right_boundary]) {
				if (height[left_boundary + 1] <
				    height[left_boundary]) {
					rain += height[left_boundary] -
						height[left_boundary + 1];
					height[left_boundary + 1] =
						height[left_boundary];
				}
				left_boundary++;

			} else {
				if (height[right_boundary - 1] <
				    height[right_boundary]) {
					rain += height[right_boundary] -
						height[right_boundary - 1];
					height[right_boundary - 1] =
						height[right_boundary];
				}
				right_boundary--;
			}
		}
		return rain;
	}
};
int main()
{
	Solution S;
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	S.trap(height);
}
