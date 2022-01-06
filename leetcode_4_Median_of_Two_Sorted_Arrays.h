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

		sumV.reserve(sumSize);

		while (i < sumSize)
		{
			int* a = nullptr;
			int* b = nullptr;

			if (num1In < size1)
			{
				a = &nums1[num1In];
			}

			if (num2In < size2)
			{
				b = &nums2[num2In];
			}

			if (nullptr != a && nullptr != b)
			{

				if (*a < *b)
				{
					sumV.push_back(*a);
					num1In++;
				}
				else
				{
					sumV.push_back(*b);
					num2In++;
				}
			}
			else
			{
				if (nullptr == a)
				{
					if (nullptr != b)
					{
						sumV.push_back(*b);
						num2In++;
					}
				}

				if (nullptr == b)
				{
					if (nullptr != a)
					{
						sumV.push_back(*a);
						num1In++;
					}
				}
			}

			i++;
		}

		int hi = (sumSize / 2);

		if (sumSize % 2 == 0)
		{
			return  (sumV[hi - 1] + sumV[hi]) / 2.0f;
		}
		else
		{
			return sumV[hi];
		}
	}
};
