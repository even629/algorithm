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
#include <vector>

using std::queue;
using std::vector;
class Solution {
    public:
	bool isParlidrome(vector<int> &vec)
	{
		int n = vec.size();
		int i = 0;
		for (i = 0; i < n / 2; i++) {
			if (vec[i] != vec[n - i - 1]) {
				return false;
			}
		}
		return true;
	}
	bool isSymmetric(TreeNode *root)
	{
		// 层次遍历
		if (root == nullptr) {
			return true;
		}
		queue<TreeNode *> que;
		vector<int> vec;
		TreeNode *tmp;
		vec.reserve(1000);

		int i, n;
		que.push(root);
		while (!que.empty()) {
			n = que.size();
			vec.clear();
			for (i = 0; i < n; i++) {
				tmp = que.front();
				que.pop();
				if (tmp == nullptr) {
					vec.push_back(-101);
					continue;
				}
				vec.push_back(tmp->val);

				que.push(tmp->left);

				que.push(tmp->right);
			}
			if (!isParlidrome(vec)) {
				return false;
			}
		}
		return true;
	}
};
