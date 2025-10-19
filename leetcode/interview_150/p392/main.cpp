#include <string>
using std::string;

class Solution {
    public:
	bool isSubsequence(string s, string t)
	{
		// 判断s是否为t的子字符串
		int i = 0, j = 0;
		int s_len = s.size();
		int t_len = t.size();

		if (s_len == 0) {
			return true;
		}
		while (i < s_len && j < t_len) {
			if (s[i] == t[j]) {
				i++;
			}
			j++;
		}
		if (i == s_len && s[i - 1] == t[j - 1]) {
			return true;
		}
		return false;
	}
};

#include <stdio.h>
int main()
{
	Solution solution;
	string s = "abc";
	string t = "ahbgdc";
	printf("%d\n", solution.isSubsequence(s, t));
}
