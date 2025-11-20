/**
 * Definition for singly-linked list.
 
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{
	}
};

class Solution {
    public:
	bool hasCycle(ListNode *head)
	{
		ListNode *low = head, *fast = head;
		do {
			if (low == nullptr || low->next == nullptr) {
				return false;
			} else {
				low = low->next;
			}
			if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr) {
				return false;
			} else {
				fast = fast->next->next;
			}

		} while (low != fast);

		if (low != nullptr) {
			return true;
		}
		return false;
	}
};
