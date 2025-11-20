/**
 * Definition for a binary tree node.
 **/
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
#include <vector>
#include <queue>
using std::vector;
using std::queue;

class Solution {
    public:
	vector<int> rightSideView(TreeNode *root)
	{
		int i, n;
		vector<int> res;
		queue<TreeNode *> que;
		TreeNode *p;
		if (root == nullptr) {
			return res;
		}
		que.push(root);

		while (!que.empty()) {
			n = que.size();
			res.push_back(que.back()->val);
			for (i = 0; i < n; i++) {
				p = que.front();
				if (p->left) {
					que.push(p->left);
				}
				if (p->right){
				que.push(p->right);
				}
				que.pop();
			}
		}
		return res;
	}
};
