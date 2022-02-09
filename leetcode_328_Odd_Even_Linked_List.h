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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* nodeIt = head;
        ListNode* evenNodeIt = nullptr;
        ListNode* evenNodeHead = nullptr;
        ListNode* oddNodeLast = nullptr;

        while (nodeIt)
        {
            if (nullptr == nodeIt->next)
            {
                oddNodeLast = nodeIt;
                break;
            }

            if (nullptr == evenNodeIt)
            {
                evenNodeIt = nodeIt->next;
                evenNodeHead = evenNodeIt;
            }
            else
            {
                evenNodeIt->next = nodeIt->next;
                evenNodeIt = nodeIt->next;
            }

			nodeIt->next = evenNodeIt->next;

            nodeIt = nodeIt->next;
        }

        oddNodeLast->next = evenNodeHead;

        return head;
    }
};