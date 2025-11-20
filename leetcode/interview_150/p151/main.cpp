#include <sstream>
#include <stack>
#include <string>

using std::stringstream;
using std::string;
using std::stack;

class Solution {
    public:
	string reverseWords(string s)
	{
		stack<string> st;
		stringstream ss(s);
		string tmp;
		string res;
		while (ss >> tmp) {
			st.push(tmp);
		}

		while (!st.empty()) {
			tmp = st.top();
			st.pop();
			res += tmp;
			res += " ";
		}
		res.pop_back(); // 去掉最后一个空格
		return res;
	}
};
