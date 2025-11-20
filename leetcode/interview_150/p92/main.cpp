e struct ListNode {
	int val;
	ListNode *next;
	ListNode()
		: val(0)
		, next(nullptr)
	{
	}
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{
	}
	ListNode(int x, ListNode *next)
		: val(x)
		, next(next)
	{
	}
};

class Solution {
    public:
	ListNode *reverseBetween(ListNode *head, int left, int right)
	{
		int index = 0;
		ListNode *virt_head = new ListNode;
		virt_head->next = head;
		ListNode *p = virt_head, *q;

		while (p != nullptr) {
			if (index + 1 == left) {
				break;
			}
			index++;
			p = p->next;
		}
		q = p;
		while (q != nullptr) {
			if (index == right) {
				break;
			}
			index++;
			q = q->next;
		}
		ListNode *tmp;
		while (p->next != q) {
			tmp = p->next;
			p->next = tmp->next;
			tmp->next = q->next;
			q->next = tmp;
		}
		head = virt_head->next;
		delete virt_head;
		return head;
	}
};
