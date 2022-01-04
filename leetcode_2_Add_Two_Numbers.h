class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
	ListNode* begin = nullptr;
	ListNode** itor = nullptr;
	
    int plus = 0;
        
	while(l1 != nullptr || l2 != nullptr || 0 < plus)
	{
		int val1 = (l1 != nullptr) ? l1->val : 0;
		int val2 = (l2 != nullptr) ? l2->val : 0;

		int sum = val1 + val2 + plus;
		
        if(10 <= sum)
        {
            sum -= 10;
            plus = 1;
        }
		else
		{
			plus = 0;
		}
		
		auto* node = new ListNode(sum);


		if(nullptr == begin)
		{
			begin = node;
			itor = &begin;
		}
		else
		{
			(*itor)->next = node;
			itor = &(*itor)->next;
		}
		
        if(nullptr != l1)
        {
            l1 = l1->next;
        }
        
        if(nullptr != l2)
        {
            l2 = l2->next;
        }
		
	}
      
    return begin;
   
    }
};