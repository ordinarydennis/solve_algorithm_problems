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

        if(nullptr == head)
        {
            return head;
        }

        ListNode* evenHead = head->next;

        ListNode* itEvenNode = evenHead;

        ListNode* itNode = head;

        while(itNode)
        {
            itNode->next = itEvenNode->next;

            if(nullptr == itNode->next)
            {
                itNode->next = evenHead;
                break;
            }

            itNode = itNode->next;

            itEvenNode = itNode->next;

            if(nullptr == itEvenNode)
            {
                itNode->next = evenHead;
                break;
            }

        }

        return head;
        
    }
};