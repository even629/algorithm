
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *p1 = l1, *p2 = l2;
		ListNode *l3 = new ListNode;
		ListNode *p3 = l3;
		int carry = 0, total, val1, val2;
		while (p1 != nullptr || p2 != nullptr) {
			if (p1 == nullptr) {
				val1 = 0;
			} else {
				val1 = p1->val;
				p1 = p1->next;
			}

			if (p2 == nullptr) {
				val2 = 0;
			} else {
				val2 = p2->val;
				p2 = p2->next;
			}
			total = val1 + val2 + carry;
			p3->val = total % 10;
			if (!(p1 == nullptr && p2 == nullptr)) { //最后一个没有Next
				p3->next = new ListNode;
				p3 = p3->next;
			}
			carry = total / 10;
		}
		if (carry != 0) {
			p3->next = new ListNode;
			p3 = p3->next;
			p3->val = carry;
		}

		return l3;
	}
};
