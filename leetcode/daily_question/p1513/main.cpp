#include <string>

using std::string;

class Solution {
    public:
	int numSub(string s)
	{
		long res = 0, left = 0, right = 0;
		long len;
		int n = s.size();

		while (left <= right && right < n) {
			// left找到第一个1
			while (left < n && s[left] != '1') {
				left++;
			}
			right = left;
			while (right < n && s[right] == '1') {
				right++;
			}
			// [left, right)
			len = right - left;
			res += (len + 1) * len / 2 % 1000000007;
			left = right;
		}
		return res;
	}
};
