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
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == nullptr) {
			return head;
		}

		ListNode *virt_head = new ListNode;
		virt_head->next = head;

		ListNode *prev = virt_head, *curr, *duplicate;
		int i, val;

		while (prev->next != nullptr) {
			val = prev->next->val;
			curr = prev->next;
			for (i = 0; curr != nullptr; i++) {
				if (curr->val == val) {
					curr = curr->next;
				} else {
					break;
				}
			}
			if (i == 0) {
				break;
			} else if (i == 1) {
				prev = prev->next;
				continue;
			} else {
				while (prev->next != curr) {
					duplicate = prev->next;
					prev->next = duplicate->next;
					delete duplicate;
				}
			}
		}
		head = virt_head->next;
		delete virt_head;
		return head;
	}
};
