

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

class Solution {
    public:
	bool isSame(TreeNode *left, TreeNode *right)
	{
		if (left != nullptr && right != nullptr &&
		    right->val == left->val) {
			return isSame(left->right, right->left) &&
			       isSame(left->left, right->right);
		} else if (left == nullptr && right == nullptr) {
			return true;
		} else {
			return false;
		}
	}
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr) {
			return true;
		}
		return isSame(root->left, root->right);
	}
};
