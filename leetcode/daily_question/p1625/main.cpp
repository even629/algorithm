#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using std::string;
using std::unordered_set;
using std::priority_queue;
using std::vector;

class Solution {
    private:
	unordered_set<char> ch_set;

	unordered_set<string> shift_set;

	priority_queue<string, vector<string>, std::greater<string> > min_heap;

	char sadd(char ch, int a)
	{
		ch_set.clear();
		while (1) {
			ch = ((ch - '0') + a) % 10 + '0';
			if (ch_set.count(ch) == 0) {
				ch_set.insert(ch);
			} else {
				break;
			}
		}

		return *std::min_element(ch_set.begin(), ch_set.end());
	}

	bool sshift(string &s, int b)
	{
		int n = s.size();
		b = b % n;

		string substr = s.substr(n - b, b);

		s.erase(s.end() - b, s.end());
		s.insert(s.begin(), substr.begin(), substr.end());

		if (shift_set.count(s) == 0) {
			min_heap.push(s);
			shift_set.insert(s);
			return true;
		} else {
			return false;
		}
	}

    public:
	string findLexSmallestString(string s, int a, int b)
	{
		// s的长度是偶数
		int n = s.size();
		int i;
		s.reserve(n);

		// 如果b是偶数
		if (b % 2 == 0) {
			// 直接用sadd处理所有奇数
			for (i = 1; i < n; i = 2 * i + 1) {
				s[i] = sadd(s[i], a);
			}

			while (sshift(s, b))
				; //右移b位
			return min_heap.top();
		} else { // b是奇数
			//  s[i],  i 为偶数右移b位,位置变为 (i+b) % n,n是偶数, i+b是奇数，故(i+b) %n变为奇数
			//  即其中所有的偶数都可以用sadd来处理
			// 用sadd处理所有数
			for (i = 0; i < n; i++) {
				s[i] = sadd(s[i], a);
			}
			while (sshift(s, b))
				; //右移b位
			return min_heap.top();
		}
	}
};
#include <stdio.h>
int main()
{
	Solution s;
	string str = "43987654";
	int a = 7, b = 3;
	string res = s.findLexSmallestString(str, a, b);
	printf("%s\n", res.c_str());
}
