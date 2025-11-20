

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
	vector<double> averageOfLevels(TreeNode *root)
	{
		int i, n;
		queue<TreeNode *> que;
		vector<double> res;
		TreeNode *p;
		double curr;
		if (root == nullptr) {
			return res;
		}
		que.push(root);
		while (!que.empty()) {
			n = que.size();
			curr = 0;
			for (i = 0; i < n; i++) {

				p = que.front();
				que.pop();
				curr = curr + p->val;

				if (p->left) {
					que.push(p->left);
				}
				if (p->right) {
					que.push(p->right);
				}

			}
			res.push_back(curr/n);
		}
		return res;
	}
};
