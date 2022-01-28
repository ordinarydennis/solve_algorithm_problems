class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        map<int, ListNode*> nodeMap;

        ListNode* node = head;

        int i = 0;
        while (node)
        {
            nodeMap.emplace(i++, node);
            node = node->next;
        }

        if (i == 1)
        {
            return nullptr;
        }

        if (i == n)
        {
            head = head->next;
        }
        else
        {
            ListNode* preNode = nodeMap[i - n - 1];
            preNode->next = preNode->next->next;
        }

        return head;

    }
};