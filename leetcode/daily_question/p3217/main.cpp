#include <climits>
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

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
    public:
	ListNode *modifiedList(vector<int> &nums, ListNode *head)
	{
		int i, n;
		ListNode dummy;
		dummy.next = head;
		dummy.val = INT_MAX;
		ListNode *p = &dummy;

		n = nums.size();

		unordered_set<int> uset;
		ListNode *tmp;

		for (i = 0; i < n; i++) {
			uset.insert(nums[i]);
		}

		while (p->next) {
			if (uset.count(p->next->val) != 0) {
				tmp = p->next;
				p->next = tmp->next;
				delete tmp;
			}else{
			    p = p->next;
			}
		}
		return dummy.next;
	}
};

#include <iostream>
using std::cout;
using std::endl;

int main() {
	vector<int> nums = {1, 2, 3};
	ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

	Solution s;
	ListNode *res = s.modifiedList(nums, head);

	// 输出结果
	while (res) {
		cout << res->val;
		if (res->next) cout << " -> ";
		res = res->next;
	}
	cout << endl;

	return 0;
}
