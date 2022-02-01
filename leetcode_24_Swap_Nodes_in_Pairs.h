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
    ListNode* swapPairs(ListNode* head) {

        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* curNode = head;
        ListNode* ret = nullptr;
        ListNode* pre = nullptr;

        while (curNode && curNode->next)
        {
            ListNode* n = curNode->next;
            ListNode* nn = n->next;

            n->next = curNode;
            curNode->next = nn;

            if (pre)
            {
                pre->next = n;
            }

            if (nullptr == ret)
            {
                ret = n;
            }

            pre = curNode;
            curNode = nn;
        }

        return ret;

    }
};