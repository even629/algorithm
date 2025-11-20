struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode()
		: val(0)
		, left(nullptr)
		, right(nullptr)
	{
	}
	TreeNode(int x)
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x)
		, left(left)
		, right(right)
	{
	}
};

#include <stack>
#include <climits>
using std::stack;

class Solution {
    public:
	bool isValidBST(TreeNode *root)
	{
		stack<TreeNode *> st;
		TreeNode *p = root, *left, *right;
		long long last = LONG_MIN;
		while (p || !st.empty()) {
			if (p) {
				st.push(p);
				p = p->left;
			} else {
				// visit
				p = st.top();
				st.pop();
				if (p->val <= last) {
					return false;
				}
				last = p->val;
				p = p->right;
			}
		}
		return true;
	}
};
