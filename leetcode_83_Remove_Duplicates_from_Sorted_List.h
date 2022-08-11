/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {

		std::unordered_set<int> checker;

		ListNode* iter = head;
		ListNode* pre = nullptr;

		while (iter)
		{
			bool isDeleted = false;
			if (checker.count(iter->val))
			{
				pre->next = iter->next;
				isDeleted = true;
			}
			else
			{
				checker.insert(iter->val);
			}

			if (false == isDeleted)
			{
				pre = iter;
			}
			
			iter = iter->next;

		}

		return head;

	}
};