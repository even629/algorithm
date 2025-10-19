#include <string>
#include <unordered_set>
#include <algorithm>
#include <queue>

using std::string;
using std::unordered_set;
using std::queue;

class Solution {
    private:
	void sadd(string &s, int a)
	{
		int i, n;
		n = s.size();
		for (i = 1; i < n; i += 2) {
			s[i] = ((s[i] - '0') + a) % 10 + '0';
		}
	}

	void sshift(string &s, int b)
	{
		int n = s.size();
		b = b % n;

		string substr = s.substr(n - b, b);

		s.erase(s.end() - b, s.end());
		s.insert(s.begin(), substr.begin(), substr.end());
	}

    public:
	string findLexSmallestString(string s, int a, int b)
	{
		unordered_set<string> visited;
		queue<string> q;
		string res = s, cur, t;

		q.push(s);
		visited.insert(s);
		// BFS
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			res = min(res, cur);
			// 两条分支累加或者轮转

			// 累加操作
			t = cur;
			sadd(t, a);
			if (!visited.count(t)) {
				visited.insert(t);
				q.push(t);
			}

			// 轮转操作
			t = cur;
			sshift(t, b);
			if (!visited.count(t)) {
				visited.insert(t);
				q.push(t);
			}
		}

		return res;
	}
};
