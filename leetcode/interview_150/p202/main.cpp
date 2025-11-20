#include <unordered_set>

using std::unordered_set;

class Solution {
    public:
	int ops(int n)
	{
		int res = 0;
		int num;
		while (n) {
			num = n % 10;
			res += num * num;
			n /= 10;
		}
		return res;
	}
	bool isHappy(int n)
	{
		unordered_set<int> numbers;
		int i;
		for (i = n; numbers.count(i) == 0; i = ops(i)) {
			if (i == 1) {
				return true;
			}
			numbers.insert(i);
		}

		return false;
	}
};
