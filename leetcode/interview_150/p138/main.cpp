#include <stddef.h>
#include <unordered_map>

using std::unordered_map;
class Node {
    public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
    public:
	Node *copyRandomList(Node *head)
	{
		// DFS

		unordered_map<Node *, int> original_nodemap;
		unordered_map<int, Node *> new_nodemap;
		Node *p = head, *new_head = new Node(-1), *q = new_head;

		int i = 0;
		while (p != NULL) {
			q->next = new Node(p->val);
			q = q->next;
			new_nodemap[i] = q;
			original_nodemap[p] = i;
			i++;
			p = p->next;
		}

		q = new_head;
		new_head = new_head->next;
		delete q;

		q = new_head;
		p = head;
		while (q != NULL && p != NULL) {
			if (p->random == NULL) {
				q->random = NULL;
			} else {
				q->random = new_nodemap[original_nodemap[p->random]];
			}

			q = q->next;
			p = p->next;
		}

		return new_head;
	}
};
