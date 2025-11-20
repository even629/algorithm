#include <string>
#include <stack>

using std::stack;
using std::string;

class Solution {
    public:
	string conv_suffix_expr(string &s)
	{
		string res;
		// 存数字
		stack<char> st1;
		// 存符号
		stack<char> st2;
		// 中缀表达式转后缀表达式
		// -转为+负数
		for (char &ch : s) {
			if (ch == '+' || ch == '-' || ch == '(' || ch == ')') {
			} else {
				st1.push(ch);
			}
		}
	}
	int suffix_expr_cal(string &s)
	{
	}
	int calculate(string s)
	{
		string suffix_expr = conv_suffix_expr(s);
		return suffix_expr_cal(suffix_expr);
	}
};
