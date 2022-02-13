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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		auto* p1 = headA;
		auto* p2 = headB;

		while (p1 && p2 && p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;

			if (p1 == p2)
				return p1;

			if (nullptr == p1)
				p1 = headB;

			if (nullptr == p2)
				p2 = headA;

		}

		return p1;
	}
};
//[4,1,8,4,5]
//[5, 6, 1, 8, 4, 5]
int main()
{
	Solution s;

	ListNode* headA;

	auto n1 = ListNode(4);
	auto n2 = ListNode(1);
	auto n3 = ListNode(8);
	auto n4 = ListNode(4);
	auto n5 = ListNode(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	headA = &n1;

	ListNode* headB;

	auto b1 = ListNode(5);
	auto b2 = ListNode(6);
	auto b3 = ListNode(1);

	b1.next = &b2;
	b2.next = &b3;
	b3.next = &n3;

	headB = &b1;

	s.getIntersectionNode(headA, headB);

}