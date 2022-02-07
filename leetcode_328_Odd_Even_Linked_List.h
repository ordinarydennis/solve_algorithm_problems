//Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.
//
//The first node is considered odd, and the second node is even, and so on.
//
//Note that the relative order inside both the evenand odd groups should remain as it was in the input.
//
//You must solve the problem in O(1) extra space complexityand O(n) time complexity.

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

//Input: head = [2, 1, 3, 5, 6, 4, 7]
//Output : [2, 3, 6, 7, 1, 5, 4]

//[1,2,3,4,5]
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        ListNode* nodeIt = head;
        ListNode* evenNodeIt = nullptr;
        ListNode* evenNodeHead = nullptr;
        ListNode* oddNodeLast = nullptr;
        //짝수 노드를 가져오면서 홀수 노드끼리 연결해야 한다.
        while (nodeIt)
        {
            if (nullptr == nodeIt->next)
            {
                break;
            }

            if (nullptr == evenNodeIt)
            {
                evenNodeIt = nodeIt->next;
                evenNodeHead = evenNodeIt;
            }
            else
            {
                //2 > 4
                evenNodeIt->next = nodeIt->next;
                evenNodeIt = nodeIt->next;
            }

            //1 > 3 연결
            //3 > 5 연결
            if (evenNodeIt)
            {
                nodeIt->next = evenNodeIt->next;

				//3을 1번째로 잡는다.
				if (nullptr != nodeIt->next)
				{
                    nodeIt = nodeIt->next;
				}
                else
                {
					oddNodeLast = nodeIt;
                    nodeIt = nullptr;
					break;
                }
            }
        }

        oddNodeLast->next = evenNodeHead;

        return head;

    }
};