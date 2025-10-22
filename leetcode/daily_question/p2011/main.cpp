#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public:
	int finalValueAfterOperations(vector<string> &operations)
	{
		int res = 0;
		int n = operations.size();
		int i;
		for (i = 0; i < n; i++) {
			if (operations[i].compare("++X") == 0 ||
			    operations[i].compare("X++") == 0) {
				res++;
			} else if (operations[i].compare("--X") ||
				   operations[i].compare("X--")) {
				res--;
			}
		}
		return res;
	}
};
