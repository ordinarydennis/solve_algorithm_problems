//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//
//		vector<int> sum;
//
//		int nums1Size = nums1.size();
//		int nums2Size = nums2.size();
//
//		bool is1Empty = false;
//		bool is2Empty = false;
//		if (0 == nums1Size)
//		{
//			is1Empty = true;
//		}
//
//		if (0 == nums2Size)
//		{
//			is2Empty = true;
//		}
//		int sizeSum = nums1Size + nums2Size;
//		sum.reserve(sizeSum);
//
//		int maxSize = (nums1Size < nums2Size) ? nums2Size : nums1Size; //2
//
//		int i = 0;
//		while (i < maxSize)
//		{
//			int num1 = 0;
//			int num2 = 0;
//
//			if (i < nums1Size)
//			{
//				num1 = nums1[i];
//			}
//
//			if (i < nums2Size)
//			{
//				num2 = nums2[i];
//			}
//
//			if (num1 < num2)
//			{
//				if (false == is1Empty)
//				{
//					sum.push_back(num1);
//				}
//				
//				if (false == is2Empty)
//				{
//					sum.push_back(num2);
//				}
//			}
//			else
//			{
//				if (false == is2Empty)
//				{
//					sum.push_back(num2);
//				}
//
//				if (false == is1Empty)
//				{
//					sum.push_back(num1);
//				}
//			}
//
//			i++;
//
//		}
//
//		if (sizeSum == 1)
//		{
//			return sum[0];
//		}
//
//		int hi = (sizeSum / 2);
//
//		if (sizeSum % 2 == 0)
//		{
//			double sumF = sum[hi - 1] + sum[hi];
//			return sumF / 2.0f;
//		}
//		else
//		{
//			return sum[hi];
//		}
//	}
//};


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int num1In = 0;
		int num2In = 0;

		int size1 = nums1.size();
		int size2 = nums2.size();

		int sumSize = size1 + size2;

		bool empty1 = nums1.empty();
		bool empty2 = nums2.empty();

		int i = 0;

		std::vector<int> sumV;

		while (i < sumSize)
		{
			int a = 0;
			int b = 0;
			if (false == empty1)
			{
				if (num1In < size1)
				{
					a = nums1[num1In];
				}
			}

			if (false == empty2)
			{
				if (num2In < size2)
				{
					b = nums2[num2In];
				}
			}

			if (a < b)
			{
				sumV.push_back(a);
				num1In++;
			}
			else
			{
				sumV.push_back(b);
				num2In++;
			}

			i++;
		}

		int hi = (sumSize / 2);

		if (sumSize % 2 == 0)
		{
			double sumF = sumV[hi - 1] + sumV[hi];
			return sumF / 2.0f;
		}
		else
		{
			return sumV[hi];
		}
	}
};
