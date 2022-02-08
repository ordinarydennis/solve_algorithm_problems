#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

		ListNode* aIt = headA;
		ListNode* bIt = headB;

		ListNode* nNode = nullptr;

		while (aIt->next)
		{
			nNode = aIt->next;

			auto* temp = nNode->next;

			nNode->next = aIt;

			if (nullptr == temp)
			{
				aIt = nNode;
				break;
			}

			aIt = temp;

			if (nullptr == aIt->next)
			{
				aIt = nNode;
				break;
			}
		}

		//aIt 라스트 노드

		while (bIt->next)
		{
			nNode = bIt->next;

			auto* temp = nNode->next;

			nNode->next = bIt;

			if (nullptr == temp)
			{
				bIt = nNode;
				break;
			}

			bIt = temp;
		}

		//bIt 라스트 노드

		while (bIt->val != aIt->val)
		{
			bIt = bIt->next;
			aIt = aIt->next;
		}

		ListNode* ret = nullptr;
		while (bIt->val == aIt->val)
		{
			ret = bIt;
			bIt = bIt->next;
			aIt = aIt->next;

			if (bIt->val != aIt->val)
			{
				break;
			}
		}

		return ret;

	}
};

//[4,1,8,4,5]
//[5, 6, 1, 8, 4, 5]
int main()
{
	Solution s;

	ListNode* headA;

	auto a = ListNode(4);
	auto a1 = ListNode(1);
	auto a2 = ListNode(8);
	auto a3 = ListNode(4);
	auto a4 = ListNode(5);

	headA = &a;
	a.next = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;

	ListNode* headB;

	auto b = ListNode(5);
	auto b1 = ListNode(6);
	auto b2 = ListNode(1);
	auto b3 = ListNode(8);
	auto b4 = ListNode(4);
	auto b5 = ListNode(5);

	headB = &b;
	b.next = &b1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &b4;
	b4.next = &b5;

	s.getIntersectionNode(headA, headB);

}