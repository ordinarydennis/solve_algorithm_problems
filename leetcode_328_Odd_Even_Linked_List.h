class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* evenHead = head->next;

        ListNode* itEvenNode = evenHead;

        ListNode* itNode = head;

        while (itNode)
        {
            itNode->next = itEvenNode->next;

            if (nullptr == itNode->next)
            {
                itNode->next = evenHead;
                break;
            }

            itNode = itNode->next;

            if (nullptr == itNode->next)
            {
                itNode->next = evenHead;
                itEvenNode->next = nullptr;
                break;
            }

            itEvenNode->next = itNode->next;

            itEvenNode = itEvenNode->next;

        }

        return head;

    }
};