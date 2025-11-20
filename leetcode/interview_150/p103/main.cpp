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
#include <algorithm>

using std::vector;
using std::queue;

class Solution {
    public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		int i, n;
		queue<TreeNode *> que;
		vector<vector<int> > res;
		bool reverse = false;
		TreeNode *p;
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
			if (reverse) {
				std::reverse(vec.begin(), vec.end());
			}
			res.push_back(vec);
			reverse = !reverse;
		}
		return res;
	}
};
