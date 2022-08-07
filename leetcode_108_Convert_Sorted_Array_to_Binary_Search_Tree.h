/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Research about height-balanced binary search tree is required
class Solution {

	TreeNode* generateBST(int start, int end, const vector<int>& nums)
	{
		if (end < start)
		{
			return nullptr;
		}

		int middleIndex = (start + end) / 2;

		int val = nums[middleIndex];

		TreeNode* root = new TreeNode(val);

		root->left = generateBST(start, middleIndex - 1, nums);
		root->right = generateBST(middleIndex + 1, end, nums);

		return root;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		return generateBST(0, nums.size() - 1, nums);

	}
};