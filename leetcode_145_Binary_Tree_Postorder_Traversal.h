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

    std::vector<int> ret;

    void Traversal(TreeNode* root)
    {

        if (root->left)
        {
            Traversal(root->left);
        }

		if (root->right)
		{
			Traversal(root->right);
		}

        ret.push_back(root->val);

    }

public:
    vector<int> postorderTraversal(TreeNode* root) {

        if (root)
        {
            Traversal(root);
        }

        return ret;

    }
};