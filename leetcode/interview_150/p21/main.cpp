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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		// 创建一个头节点
		ListNode *list3_head = new ListNode;
		ListNode *p = list3_head;

		while (list1 != nullptr || list2 != nullptr) {
			if (list1 == nullptr && list2 != nullptr) {
				p->next = list2;
				list2 = list2->next;
				p = p->next;
				p->next = nullptr;
			} else if (list1 != nullptr && list2 == nullptr) {
				p->next = list1;
				list1 = list1->next;
				p = p->next;
				p->next = nullptr;
			} else if (list1 != nullptr && list2 != nullptr) {
				if (list1->val <= list2->val) {
					p->next = list1;
					list1 = list1->next;
					p = p->next;
					p->next = nullptr;
				} else {
					p->next = list2;
					list2 = list2->next;
					p = p->next;
					p->next = nullptr;
				}
			}
		}
		p = list3_head;
		list3_head = list3_head->next;
		delete p;
		return list3_head;
	}
};
