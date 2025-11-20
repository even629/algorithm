#include <stack>
using std::stack;

class MinStack {
    private:
	// 记录与最小值的偏移
	stack<long> st;
	long min_val;

    public:
	MinStack()
	{
	}

	void push(int val)
	{
		if (st.empty()) {
			st.push(0);
			min_val = val;
		} else {
			long diff = val - min_val;
			st.push(diff);
			if (diff < 0) {
				min_val = val;
			}
		}
	}

	void pop()
	{
		long diff = st.top();
		st.pop();
		if (diff < 0) {
			min_val = min_val - diff; //恢复上一个最小值
		}
	}

	int top()
	{
		long offset = st.top();
		if (offset <= 0) {
			return (int)min_val;
		} else {
			return (int)(min_val + offset);
		}
	}

	int getMin()
	{
		return (int)min_val;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
