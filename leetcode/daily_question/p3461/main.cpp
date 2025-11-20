#include <string>
#include <queue>
using std::string;
using std::queue;

class Solution {
    public:
	bool hasSameDigits(string s)
	{
		queue<int> que;
		int val1, val2;
		for (char ch : s) {
			que.push(ch - '0');
		}
		que.push(-1);

		while (que.size() > 3) {
			val1 = que.front();
			que.pop();

			val2 = que.front();
			if (val2 == -1) {
				que.pop();
				que.push(-1);
				continue;
			}
			que.push((val1 + val2) % 10);
		}

		if (que.size() == 3) {
			val1 = que.front();
			que.pop();
			val2 = que.front();
			if (val1 == val2) {
				return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution S;
	S.hasSameDigits("3902");
}
