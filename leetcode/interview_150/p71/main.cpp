#include <string>
#include <stack>
#include <sstream>
using std::string;
using std::stringstream;
using std::stack;

class Solution {
    public:
	string simplifyPath(string path)
	{
		string res, curr;
		stringstream ss(path);
		stack<string> st;
		while (std::getline(ss, curr, '/')) {
			if (curr.empty()) {
				continue;
			}

			if (curr.compare("..") == 0) {
				if (!st.empty()) {
					st.pop();
				} else {
					continue;
				}

			} else if (curr.compare(".") == 0) {
				continue;
			} else {
				st.push(curr);
			}
		}
		while (!st.empty()) {
			curr = st.top();
			st.pop();
			res.insert(0, curr);
			res.insert(0, "/");
		}
		if (res.empty()) {
			res = "/";
		}
		return res;
	}
};
