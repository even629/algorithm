#include <string>
#include <vector>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
    public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> st;
		int val1, val2, res = 0;
		for (string &token : tokens) {
			if (!token.compare("+") || !token.compare("-") || !token.compare("*") || !token.compare("/")) {
				val1 = st.top();
				st.pop();
				val2 = st.top();
				st.pop();
				if (!token.compare("+")) {
					st.push(val2 + val1);
				} else if (!token.compare("-")) {
					st.push(val2 - val1);
				} else if (!token.compare("*")) {
					st.push(val2 * val1);
				} else if (!token.compare("/")) {
					st.push(val2 / val1);
				}
			} else {
				st.push(std::stoi(token));
			}
		}
		return st.top();
	}
};
