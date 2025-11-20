
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
#include <algorithm>
#include <climits>
#include <cmath>

using std::stack;

class Solution {
    public:
	int getMinimumDifference(TreeNode *root)
	{ // 二叉搜索树，中序遍历是按顺序排列的

		stack<TreeNode *> st;
		TreeNode *p = root, *left, *right;
		int res = INT_MAX, last = INT_MAX;
		while (p || !st.empty()) {
			if (p) {
				st.push(p);
				p = p->left;
			} else {
			    // visit
				p = st.top();
				st.pop();
				res = std::min(res, std::abs(last, p->val));
				
				last = p->val;
				p = p->right;
			}
		}
		return res;
	}
};
