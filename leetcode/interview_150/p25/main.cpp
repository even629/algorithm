struct ListNode {
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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		int i, j;
		ListNode *virt_head = new ListNode;
		virt_head->next = head;
		ListNode *group_tail;
		ListNode *res = head;
		ListNode *tmp, *p;

		for (i = 0; virt_head->next != nullptr; i++) {
			p = virt_head;
			group_tail = virt_head->next; //反转后下一组的前驱
			// 从virt_head开始往后走k个结点
			for (j = 0; j < k && p != nullptr; j++) {
				p = p->next;
			}

			if (p == nullptr) { // 最后一组不足k个
				break;
			}

			while (virt_head->next != p) {
				tmp = virt_head->next;
				virt_head->next = tmp->next;
				tmp->next = p->next;
				p->next = tmp;
			}
			if (i == 0) {
				res = virt_head->next;
				delete virt_head;
			}
			virt_head = group_tail;
		}

		return res;
	}
};
