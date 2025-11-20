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
#include <queue>

class Solution {
    public:
	int maxDepth(TreeNode *root)
	{
		if (root == NULL) {
			return 0;
		}
		// 层次遍历求最大深度
		int depth = 1;
		std::queue<TreeNode *> que;

		TreeNode *tmp;
		int i, qsize;
		que.push(root);

		while (!que.empty()) {
			qsize = que.size();
			for (i = 0; i < qsize; i++) {
				tmp = que.front();
				que.pop();
				if (tmp->left != NULL) {
					que.push(tmp->left);
				}
				if (tmp->right != NULL) {
					que.push(tmp->right);
				}
			}
			depth++;
		}
		return depth;
	}
};
