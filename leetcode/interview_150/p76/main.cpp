#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

class Solution {
    public:
	string minWindow(string s, string t)
	{
		unordered_map<char, int> need;
		unordered_map<char, int> window;
		for (char &ch : t) {
			need[ch]++;
		}
		int i = 0, j = 0, n = s.size();
		int start;
		int min_len = n + 1;
		int valid = 0;
		for (j = 0; j < n; j++) {
			if (!need.count(s[j])) {
				continue;
			}
			window[s[j]]++;

			if (window[s[j]] == need[s[j]]) {
				valid++;
			}
			while (valid == need.size()) { //收缩left
				if (j - i + 1 < min_len) {
					start = i;
					min_len = j - i + 1;
				}
				if (need.count(s[i])) {
					if (window[s[i]] == need[s[i]]) {
						valid--;
					}
					window[s[i]]--;
				}
				i++; // 左移窗口
			}
		}
		return min_len == n + 1 ? "" : s.substr(start, min_len);
	}
};
