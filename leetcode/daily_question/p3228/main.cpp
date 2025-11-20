#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
    public:
	int maxOperations(string s)
	{
		int i, n = s.size();
		int max_ops = 0;

		int last_1_pos;
		vector<int> vec;
		for (i = 0; i < n; i++) {
			if (s[i] == '1') {
				last_1_pos = i;
				break;
			}
		}
		while (i < n) {
			while (i < n && s[i] == '1') {
				i++;
			}

			vec.push_back(i - last_1_pos);

			while (i < n && s[i] == '0') {
				i++;
			}
			last_1_pos = i;
		}
		if (s.back() == '1' && !vec.empty()) {
			vec.pop_back();
		}
		n = vec.size();
		for (i = 0; i < n; i++) {
			max_ops += vec[i] * (n - i);
		}
		return max_ops;
	}
};
