#include <string>
#include <stack>

using std::stack;
using std::string;

class Solution {
    public:
	bool isValid(string s)
	{
		stack<char> st;
		char curr;
		for (char &ch : s) {
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			} else if (!st.empty() && ch == ')') {
				curr = st.top();
				st.pop();
				if (curr != '(') {
					return false;
				}
			} else if (!st.empty() && ch == ']') {
				curr = st.top();
				st.pop();
				if (curr != '[') {
					return false;
				}
			} else if (!st.empty() && ch == '}') {
				curr = st.top();
				st.pop();
				if (curr != '{') {
					return false;
				}
			} else {
				return false;
			}
		}

		return st.empty();
	}
};
