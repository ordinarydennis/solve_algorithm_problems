class Solution {
public:
	int maxArea(vector<int>& height) {

		int s = height.size();

		int max = 0;

		for (int a = 0; a < s - 1; a++)
		{
			for (int b = a + 1; b < s; b++)
			{

				int m = (height[a] < height[b]) ? height[a] : height[b];
				int h = b - a;
				if (max < (m * h))
				{
					max = (m * h);
				}
			}
		}

		return max;

	}
};