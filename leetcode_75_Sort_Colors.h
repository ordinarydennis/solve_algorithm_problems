//class Solution {
//
//	void swap(int& a, int& b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//
//public:
//	void sortColors(vector<int>& nums) {
//
//		int l = 0;
//		int m = 0;
//		int r = nums.size() - 1;
//
//		while (m <= r)
//		{
//			if (0 == nums[m])
//			{
//				swap(nums[l], nums[m]);
//				l++;
//				m++;
//			}
//			else if (1 == nums[m])
//			{
//				m++;
//			}
//			else if (2 == nums[m])
//			{
//				swap(nums[m], nums[r]);
//				r--;
//			}
//		}
//	}
//};

class Solution {

public:
	void sortColors(vector<int>& nums) {

		int r = 0, w = 0, b = 0; // label the end of different colors;

		for (int num : nums)
		{
			if (num == 0) 
			{ 
				nums[b++] = 2;
				nums[w++] = 1; 
				nums[r++] = 0; 
			}
			else if (num == 1) 
			{ 
				nums[b++] = 2; 
				nums[w++] = 1; 
			}
			else if (num == 2)
			{
				b++;
			}
		}
	}
};