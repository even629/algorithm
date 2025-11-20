/*
// Definition for a Node.
*/
#include <cstddef>
class Node {
    public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node()
		: val(0)
		, left(NULL)
		, right(NULL)
		, next(NULL)
	{
	}

	Node(int _val)
		: val(_val)
		, left(NULL)
		, right(NULL)
		, next(NULL)
	{
	}

	Node(int _val, Node *_left, Node *_right, Node *_next)
		: val(_val)
		, left(_left)
		, right(_right)
		, next(_next)
	{
	}
};

#include <queue>
using std::queue;

class Solution {
    public:
	Node *connect(Node *root)
	{
		if (root == nullptr) {
			return root;
		}
		// 层次遍历
		int i, n;
		Node *curr, *last;
		queue<Node *> que;

		que.push(root);

		while (!que.empty()) {
			n = que.size();
			last = nullptr;
			for (i = 0; i < n; i++) {
				curr = que.front();
				que.pop();
				if (last != nullptr) {
					last->next = curr;
				}

				if (curr->left != nullptr) {
					que.push(curr->left);
				}
				if (curr->right != nullptr) {
					que.push(curr->right);
				}

				last = curr;
			}
			curr->next = nullptr;
		}
		return root;
	}
};
