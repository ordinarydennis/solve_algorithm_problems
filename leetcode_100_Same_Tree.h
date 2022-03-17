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
class Solution {

    bool traversal(TreeNode* p, TreeNode* q)
    {
        if (nullptr == p && nullptr == q)
			return true;
		
		if (nullptr == p && q)
			return false;

		if (p && nullptr == q)
			return false;

		if (p->val != q->val)
			return false;

		if (false == traversal(p->left, q->left))
			return false;

		if (false == traversal(p->right, q->right))
			return false;

        return true;
    }


public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        return traversal(p, q);

    }
};