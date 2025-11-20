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
#include <utility>
using std::vector;
using std::queue;

class Solution {
    public:
	vector<vector<int> > levelOrder(TreeNode *root)
	{
		int i, n;
		queue<TreeNode *> que;
		vector<vector<int> > res;
		TreeNode *p;
		res.reserve(32); // 预留空间，避免多次扩容
		if (root == nullptr) {
			return res;
		}
		que.push(root);
		while (!que.empty()) {
			n = que.size();
			vector<int> vec(n);
			for (i = 0; i < n; i++) {
				p = que.front();
				que.pop();
				vec[i] = p->val;
				if (p->left) {
					que.push(p->left);
				}
				if (p->right) {
					que.push(p->right);
				}
			}
			res.push_back(std::move(vec));
		}
		return res;
	}
};
