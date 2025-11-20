#include <string>
#include <unordered_set>
#include <algorithm>
using std::string;
using std::unordered_set;

// 给定一个字符串 s ，找出其中不含有重复字符的 最长 子串 的长度。
class Solution {
    public:
	int lengthOfLongestSubstring(string s)
	{
		int i = 0, j = 0;
		int n = s.size();
		unordered_set<char> uset;
		int len = 0;
		for (j = 0; j < n; j++) {
			if (uset.count(s[j])) {
				len = std::max(len, (int)uset.size());
				// 左边界收缩
				while (s[i] != s[j]) {
					uset.erase(s[i]);
					i++;
				}
				if (s[i] == s[j]) { //直到删除当前串
					uset.erase(s[i]);
					i++;
				}
			}
			uset.insert(s[j]);
		}
		return std::max(len, (int)uset.size());
	}
};
